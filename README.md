# TICKET_MANAGEMENT
NAME : Falguni
ROLL NO. : 2401360002
COURSE : BTECH CSE (Ui/Ux)


Department: CSE 
Session: 2025-26 
Programme: BTech, BCA 
Semester: 3rd 
Course Code: ENCS253 
Course: Data Structures 
Lab Assignment Details 
Theme: Stacks, Queues, and Linked Lists 
Lab Assignment Number: 02 
Total Marks: 10 
Contribution: 20% of internal evaluation 
CO Mapping: CO 2, CO 3 
Submission Requirements:  
• Submit individually via GitHub and provide the link of submission by 30th 
September 2025.  
• Late submissions, copied assignments, or AI-generated text will not be accepted.  
• Use the dedicated lab assignment format shared in classes. 
Problem: Develop the Customer Support Ticket System 
Description: The Customer Support Ticket System is a software solution designed to manage 
incoming customer tickets using queues, stacks, and linked lists. This system enables 
dynamic addition of tickets, prioritizes urgent tickets, supports undo operations, and 
processes tickets in a round-robin manner. The lab assignment focuses on implementing these 
data structures in C++ or Python to address real-world customer support scenarios and 
analyzing their functionality. 
Implementation Sub-Problems 
1. Create a singly linked list for dynamically adding tickets to the system.  
2. Use a stack for undo operations (e.g., remove last inserted ticket).  
3. Implement a priority queue to process urgent tickets first.  
4. Demonstrate circular queue for round-robin ticket processing.  
5. Represent billing history using polynomial linked lists for record comparison. 
Evaluation Metrics 
Metric 
Problem Understanding 
Problem Solving Approach 
Completion of the Problem 
Participation during Class/Lab 
Explanation of the Assignment 
Attendance 
Marks Excellent Very Good Satisfactory Poor 
2 
2 
2 
2 
1 
1 
Assignment Objectives 
2 
2 
2 
2 
1 
1 
1.5 
1.5 
1.5 
1.5 
0.75 
0.75 
1 
1 
1 
1 
0.5 
0.5 
0.5 
0.5 
0.5 
0.5 
0.25 
0.25 
a. Develop a foundational understanding of C++ and Python programming and linear data 
structures (linked lists, stacks, queues). 
b. Gain practical experience with singly linked lists, stacks, priority queues, and circular 
queues. 
c. Implement real-world applications for customer support ticket management. 
d. Understand the application of stacks and queues in undo operations and priority-based 
systems. 
e. Apply polynomial linked lists for record comparison in billing history. 
Assignment Instructions 
1. Ticket ADT Design 
Attributes: 
a. TicketID: Integer, unique identifier for the ticket. 
b. CustomerName: String, name of the customer. 
c. IssueDescription: String, details of the customer’s issue. 
d. Priority: Integer, priority level of the ticket (e.g., 1 for urgent).  
Methods: 
a. insertTicket(data): Insert a new ticket record into the singly linked list. 
b. deleteTicket(TicketID): Remove a ticket record based on the TicketID. 
c. retrieveTicket(TicketID): Retrieve ticket details based on the TicketID. 
2. Customer Support Ticket System 
Attributes: 
a. TicketList: A singly linked list to store ticket records dynamically. 
b. UndoStack: A stack to store recent ticket changes for undo functionality. 
c. PriorityQueue: A priority queue to manage urgent tickets. 
d. CircularQueue: A circular queue for round-robin ticket processing. 
e. BillingHistory: A polynomial linked list to represent billing records. 
Methods: 
a. addTicketRecord(): Add a new ticket to the singly linked list and update the undo stack. 
b. undoTicketOperation(): Revert the most recent ticket operation using the stack. 
c. processPriorityTickets(): Enqueue and dequeue tickets in the priority queue based on 
urgency. 
d. processRoundRobinTickets(): Manage ticket processing using the circular queue. 
e. compareBillingHistory(): Use polynomial linked lists to compare billing records. 
Implementation Steps 
1. Define the Ticket ADT with the specified attributes and methods using a singly linked 
list structure in C++ or Python.  
2. Implement a stack-based undo mechanism to track and revert ticket operations.  
3. Develop a priority queue to process urgent tickets first.  
4. Create a circular queue for round-robin ticket processing.  
5. Implement polynomial linked lists to represent and compare billing history records. 
Evaluation Criteria 
Criteria 
Problem 
Understanding 
Problem Solving 
Approach 
Completion of the 
Problem 
Participation during 
Class/Lab 
Explanation of the 
Assignment 
Attendance 
Prerequisites 
Marks 
2 
2 
2 
1 
2 
1 
Description 
Demonstrates clear understanding of the problem 
requirements and objectives. 
Effective approach to designing and implementing linked 
lists, stacks, and queues in C++ or Python. 
Complete implementation of all required components (linked 
lists, stacks, queues, polynomial operations). 
Active engagement in class/lab discussions and activities 
related to the lab assignment. 
Clear and detailed explanation of the implemented solution 
in the submission report. 
Consistent attendance in classes/labs relevant to the lab 
assignment. 
• Familiarity with pointers and structures in C++ and basic programming in Python.  
• Basic knowledge of linked list implementation. 
Concepts Covered 
• Stacks, queues, linked lists, polynomial operations. 
Learning Outcomes 
1. Apply linear data structures (linked lists, stacks, queues) in practical customer support 
scenarios using C++ or Python.  
2. Understand the use of stacks, priority queues, and circular queues in real-world 
problems like undo operations and ticket processing.  
3. Gain proficiency in implementing polynomial linked lists for record comparison. 
Submission Guidelines 
1. Upload the lab assignment on GitHub and provide the link of submission by the 
specified deadline.  
2. Ensure code is original and follows the provided format.  
3. Include a detailed report covering: 
a. Description of the Ticket ADT. 
b. Strategy for implementing linked lists, stacks, queues, and polynomial operations in 
C++ or Python. 
c. Approach to undo operations, priority, and round-robin processing. 
d. Analysis of the system’s efficiency and functionality. 
Deliverables 
• C++ or Python source code for linked list, stack, queue, and polynomial 
implementations.  
• Sample input/output with explanation.  
• Hands-on C++ or Python code. 
Helpful References 
1. Books: 
a. "Data Structures and Algorithm Analysis in C++" by Mark Allen Weiss 
b. "Data Structures and Algorithms in Python" by Michael T. Goodrich, Roberto 
Tamassia, and Michael H. Goldwasser  
2. Tutorials: 
a. GeeksforGeeks: Linked List Data Structure 
b. GeeksforGeeks: Stack and Queue Data Structures 
c. Programiz: Stacks, Queues, and Linked Lists in C++ and Python
