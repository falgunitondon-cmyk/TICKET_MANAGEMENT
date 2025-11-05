#include <iostream>
#include <string>
using namespace std;

// Ticket ADT Structure
struct Ticket {
    int TicketID;
    string CustomerName;
    string IssueDescription;
    int Priority;
    
    Ticket(int id = 0, string name = "", string issue = "", int priority = 0) {
        TicketID = id;
        CustomerName = name;
        IssueDescription = issue;
        Priority = priority;
    }
};

// Singly Linked List Node for Tickets
struct TicketNode {
    Ticket data;
    TicketNode* next;
    
    TicketNode(Ticket t) {
        data = t;
        next = nullptr;
    }
};

// Stack Node for Undo Operations
struct StackNode {
    string operation;
    Ticket ticket;
    StackNode* next;
    
    StackNode(string op, Ticket t) {
        operation = op;
        ticket = t;
        next = nullptr;
    }
};

// Priority Queue Node
struct PriorityNode {
    Ticket data;
    PriorityNode* next;
    int priority;
    
    PriorityNode(Ticket t) {
        data = t;
        priority = t.Priority;
        next = nullptr;
    }
};

// Circular Queue Implementation
class CircularQueue {
private:
    struct QueueNode {
        Ticket data;
        QueueNode* next;
        QueueNode* prev;
        
        QueueNode(Ticket t) {
            data = t;
            next = nullptr;
            prev = nullptr;
        }
    };
    
    QueueNode* front;
    QueueNode* rear;
    int size;
    int capacity;
    
public:
    CircularQueue(int cap) {
        capacity = cap;
        front = rear = nullptr;
        size = 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void enqueue(Ticket t) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        
        QueueNode* newNode = new QueueNode(t);
        
        if (isEmpty()) {
            front = rear = newNode;
            front->next = front;
            front->prev = front;
        } else {
            newNode->next = front;
            newNode->prev = rear;
            rear->next = newNode;
            front->prev = newNode;
            rear = newNode;
        }
        size++;
        cout << "Ticket #" << t.TicketID << " added to round-robin queue" << endl;
    }
    
    Ticket dequeue() {
        if (isEmpty()) {
            return Ticket(-1, "", "", -1);
        }
        
        Ticket data = front->data;
        QueueNode* temp = front;
        
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = rear;
            rear->next = front;
        }
        
        delete temp;
        size--;
        return data;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Circular Queue: ";
        QueueNode* current = front;
        do {
            cout << current->data.TicketID << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

// Polynomial Term for Billing History
struct PolyTerm {
    int coefficient;
    int exponent;
    PolyTerm* next;
    
    PolyTerm(int coeff, int exp) {
        coefficient = coeff;
        exponent = exp;
        next = nullptr;
    }
};

class CustomerSupportSystem {
private:
    TicketNode* ticketHead;
    StackNode* undoTop;
    PriorityNode* priorityFront;
    CircularQueue* roundRobinQueue;
    PolyTerm* billingHead;
    int ticketCounter;
    
    // Helper Methods
    TicketNode* findTicket(int ticketID) {
        TicketNode* current = ticketHead;
        while (current != nullptr) {
            if (current->data.TicketID == ticketID) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    // Simple power function for polynomial evaluation
    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }
    
public:
    CustomerSupportSystem(int queueSize = 10) {
        ticketHead = nullptr;
        undoTop = nullptr;
        priorityFront = nullptr;
        roundRobinQueue = new CircularQueue(queueSize);
        billingHead = nullptr;
        ticketCounter = 1000;
        
        cout << "=== Customer Support Ticket System ===" << endl;
        cout << "System initialized successfully!" << endl;
    }
    
    ~CustomerSupportSystem() {
        // Cleanup ticket list
        TicketNode* tempTicket = ticketHead;
        while (tempTicket != nullptr) {
            TicketNode* next = tempTicket->next;
            delete tempTicket;
            tempTicket = next;
        }
        
        // Cleanup undo stack
        StackNode* tempStack = undoTop;
        while (tempStack != nullptr) {
            StackNode* next = tempStack->next;
            delete tempStack;
            tempStack = next;
        }
        
        // Cleanup priority queue
        PriorityNode* tempPriority = priorityFront;
        while (tempPriority != nullptr) {
            PriorityNode* next = tempPriority->next;
            delete tempPriority;
            tempPriority = next;
        }
        
        // Cleanup polynomial
        PolyTerm* tempPoly = billingHead;
        while (tempPoly != nullptr) {
            PolyTerm* next = tempPoly->next;
            delete tempPoly;
            tempPoly = next;
        }
        
        delete roundRobinQueue;
    }
    
    // 1. Singly Linked List Operations
    void addTicketRecord(string name, string issue, int priority) {
        Ticket newTicket(ticketCounter++, name, issue, priority);
        TicketNode* newNode = new TicketNode(newTicket);
        
        // Add to main list
        if (ticketHead == nullptr) {
            ticketHead = newNode;
        } else {
            TicketNode* temp = ticketHead;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        // Add to undo stack
        StackNode* undoNode = new StackNode("ADD", newTicket);
        undoNode->next = undoTop;
        undoTop = undoNode;
        
        cout << "Ticket #" << newTicket.TicketID << " added successfully!" << endl;
    }
    
    bool deleteTicket(int ticketID) {
        TicketNode* current = ticketHead;
        TicketNode* prev = nullptr;
        
        while (current != nullptr) {
            if (current->data.TicketID == ticketID) {
                // Add to undo stack
                StackNode* undoNode = new StackNode("DELETE", current->data);
                undoNode->next = undoTop;
                undoTop = undoNode;
                
                if (prev == nullptr) {
                    ticketHead = current->next;
                } else {
                    prev->next = current->next;
                }
                
                delete current;
                cout << "Ticket #" << ticketID << " deleted successfully!" << endl;
                return true;
            }
            prev = current;
            current = current->next;
        }
        
        cout << "Ticket #" << ticketID << " not found!" << endl;
        return false;
    }
    
    Ticket* retrieveTicket(int ticketID) {
        TicketNode* node = findTicket(ticketID);
        if (node != nullptr) {
            return &(node->data);
        }
        return nullptr;
    }
    
    void displayAllTickets() {
        if (ticketHead == nullptr) {
            cout << "No tickets in the system!" << endl;
            return;
        }
        
        cout << "\n=== All Support Tickets ===" << endl;
        cout << "---------------------------" << endl;
        TicketNode* current = ticketHead;
        while (current != nullptr) {
            cout << "ID: " << current->data.TicketID 
                 << " | Customer: " << current->data.CustomerName
                 << " | Priority: " << current->data.Priority
                 << " | Issue: " << current->data.IssueDescription << endl;
            current = current->next;
        }
        cout << "---------------------------" << endl;
    }
    
    // 2. Stack-based Undo Operations
    void undoTicketOperation() {
        if (undoTop == nullptr) {
            cout << "No operations to undo!" << endl;
            return;
        }
        
        StackNode* temp = undoTop;
        undoTop = undoTop->next;
        
        if (temp->operation == "ADD") {
            // Undo add by deleting the ticket
            deleteTicket(temp->ticket.TicketID);
            // Remove the undo entry for the delete we just did
            StackNode* tempUndo = undoTop;
            undoTop = undoTop->next;
            delete tempUndo;
            cout << "Undid ADD operation for ticket #" << temp->ticket.TicketID << endl;
        } else if (temp->operation == "DELETE") {
            // Undo delete by adding the ticket back
            TicketNode* newNode = new TicketNode(temp->ticket);
            if (ticketHead == nullptr) {
                ticketHead = newNode;
            } else {
                TicketNode* current = ticketHead;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
            cout << "Undid DELETE operation for ticket #" << temp->ticket.TicketID << endl;
        }
        
        delete temp;
    }
    
    // 3. Priority Queue Operations
    void addToPriorityQueue(int ticketID) {
        Ticket* ticket = retrieveTicket(ticketID);
        if (ticket == nullptr) {
            cout << "Ticket not found!" << endl;
            return;
        }
        
        PriorityNode* newNode = new PriorityNode(*ticket);
        
        if (priorityFront == nullptr || priorityFront->priority > newNode->priority) {
            newNode->next = priorityFront;
            priorityFront = newNode;
        } else {
            PriorityNode* current = priorityFront;
            while (current->next != nullptr && current->next->priority <= newNode->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        
        cout << "Ticket #" << ticketID << " added to priority queue" << endl;
    }
    
    void processPriorityTickets() {
        if (priorityFront == nullptr) {
            cout << "No tickets in priority queue!" << endl;
            return;
        }
        
        cout << "\n=== Processing Priority Tickets ===" << endl;
        while (priorityFront != nullptr) {
            PriorityNode* temp = priorityFront;
            priorityFront = priorityFront->next;
            cout << "Processing Ticket #" << temp->data.TicketID 
                 << " (Priority: " << temp->data.Priority << ")" << endl;
            delete temp;
        }
    }
    
    // 4. Circular Queue for Round-Robin
    void processRoundRobinTickets() {
        cout << "\n=== Round-Robin Ticket Processing ===" << endl;
        roundRobinQueue->display();
        
        if (!roundRobinQueue->isEmpty()) {
            Ticket processed = roundRobinQueue->dequeue();
            cout << "Processed Ticket #" << processed.TicketID << " in round-robin" << endl;
        } else {
            cout << "No tickets in round-robin queue!" << endl;
        }
    }
    
    void addToRoundRobin(int ticketID) {
        Ticket* ticket = retrieveTicket(ticketID);
        if (ticket != nullptr) {
            roundRobinQueue->enqueue(*ticket);
        } else {
            cout << "Ticket #" << ticketID << " not found!" << endl;
        }
    }
    
    // 5. Polynomial Linked Lists for Billing
    void addBillingTerm(int coeff, int exp) {
        PolyTerm* newTerm = new PolyTerm(coeff, exp);
        
        if (billingHead == nullptr) {
            billingHead = newTerm;
        } else {
            PolyTerm* current = billingHead;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newTerm;
        }
        
        cout << "Added billing term: " << coeff << "x^" << exp << endl;
    }
    
    void compareBillingHistory(int x) {
        if (billingHead == nullptr) {
            cout << "No billing history!" << endl;
            return;
        }
        
        cout << "\n=== Billing History Comparison ===" << endl;
        cout << "Polynomial: ";
        PolyTerm* current = billingHead;
        int total = 0;
        
        while (current != nullptr) {
            int termValue = current->coefficient * power(x, current->exponent);
            total += termValue;
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next != nullptr) {
                cout << " + ";
            }
            current = current->next;
        }
        
        cout << "\nTotal billing at x=" << x << ": " << total << endl;
    }
    
    // Main Menu
    void mainMenu() {
        int choice;
        do {
            cout << "\n=== Customer Support System Menu ===" << endl;
            cout << "1. Add New Ticket" << endl;
            cout << "2. Delete Ticket" << endl;
            cout << "3. Display All Tickets" << endl;
            cout << "4. Undo Last Operation" << endl;
            cout << "5. Add to Priority Queue" << endl;
            cout << "6. Process Priority Tickets" << endl;
            cout << "7. Add to Round-Robin Queue" << endl;
            cout << "8. Process Round-Robin Ticket" << endl;
            cout << "9. Add Billing Term" << endl;
            cout << "10. Compare Billing History" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            
            string name, issue;
            int ticketID, priority, coeff, exp, x;
            
            switch (choice) {
                case 1:
                    cout << "Enter Customer Name: ";
                    getline(cin, name);
                    cout << "Enter Issue Description: ";
                    getline(cin, issue);
                    cout << "Enter Priority (1=High, 2=Medium, 3=Low): ";
                    cin >> priority;
                    addTicketRecord(name, issue, priority);
                    break;
                    
                case 2:
                    cout << "Enter Ticket ID to delete: ";
                    cin >> ticketID;
                    deleteTicket(ticketID);
                    break;
                    
                case 3:
                    displayAllTickets();
                    break;
                    
                case 4:
                    undoTicketOperation();
                    break;
                    
                case 5:
                    cout << "Enter Ticket ID for priority queue: ";
                    cin >> ticketID;
                    addToPriorityQueue(ticketID);
                    break;
                    
                case 6:
                    processPriorityTickets();
                    break;
                    
                case 7:
                    cout << "Enter Ticket ID for round-robin: ";
                    cin >> ticketID;
                    addToRoundRobin(ticketID);
                    break;
                    
                case 8:
                    processRoundRobinTickets();
                    break;
                    
                case 9:
                    cout << "Enter coefficient: ";
                    cin >> coeff;
                    cout << "Enter exponent: ";
                    cin >> exp;
                    addBillingTerm(coeff, exp);
                    break;
                    
                case 10:
                    cout << "Enter value of x for comparison: ";
                    cin >> x;
                    compareBillingHistory(x);
                    break;
                    
                case 0:
                    cout << "Exiting system..." << endl;
                    break;
                    
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    cout << "Customer Support Ticket System" << endl;
    cout << "==============================" << endl;
    
    CustomerSupportSystem css;
    
    // Added sample data for demonstration
    css.addTicketRecord("krish", "Login issues", 1);
    css.addTicketRecord("tarun", "Payment problem", 2);
    css.addTicketRecord("aryan", "Feature request", 3);
    
    css.addBillingTerm(150, 2);
    css.addBillingTerm(75, 1);
    css.addBillingTerm(25, 0);
    
    css.mainMenu();
    
    return 0;
}