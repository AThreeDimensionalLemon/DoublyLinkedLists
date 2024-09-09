Complete your own implementation of Doubly Linked List
Attachments: 1) DoublyLinkedList.h Download DoublyLinkedList.h2) main.cpp Download main.cpp3) ListType.hDownload ListType.h

Complete the stub file for the DoublyLinkedList implementation.

Please note: Any changes to the NodeType struct, not using the NodeType struct, or changing from template Type to using a specific data type will all be cause for deductions.

You are required to implement the methods:

insertFirst
insertLast
insertNode - (insert an item at a given index)
deleteNode - (remove a specific item)
The stub file contains the basic class format to implement the virtual methods from ListType. You should only need to complete the code for these four functions. Your code must maintain (or add) the node connections both forward and backward. In the double link list class these are called next and prev.

Your code must also maintain the count variable.

You may create any helper functions you like but they should contain comments explaining why they are helpful/necessary. Hint: You may find creating a private getNode(int index) function -- which returns a link to any internal node -- helpful.

 

Pair Programming:
You may choose to work with one other student to complete this assignment.

If you choose to do this you need to implement one extra function.

This extra function should be an overloaded version of deleteNodeAtIndex that just takes in an index, deletes the node at the given index, and returns the data content of the previous. You will need to add this function to the class definition.

If you work with another person, you should only to turn in one copy of the work. Both names should be in the comment at the top of the code files.

Note: working with a partner is optional.

 

Compilation:
Though most of your code will be in the .h file you cannot actually compile that independently. If you are working with a basic terminal/commandline set up you can put all the three files into one folder and just compile the main.cpp file. i.e. g++ main.cpp

If you are working with an IDE each setup may be different. Please ask for help if you are having trouble with file configuration.

 

Testing:
I recommend compiling your code frequently. Catching any issues early on helps you know you are on the right track.

Make sure to thoroughly test your code. As a helpful tool a main function has already been provided for you. As you code you can comment and un-comment whatever sections you need to test.

You may need to use a debugger if you run across a difficult issue. In this case it may be easier to use an IDE than just Sublime.

 

Readability:
Readability will be part of your grade so make sure to use the discussed indentation, variable name choice, and comments.

You do not need to comment on every line. If you add extra comments for yourself throughout the coding process I recommend removing some before turning it in!! (When thinking about writing comments remember that anyone reading them should

 

Submission:
Make sure to include a comment at the top of the source files with your name (and your partner's name).

Create a folder which contains the header files and your testing file and name it LASTNAME_FIRSTNAME_DLL. Then zip that folder and upload it. Do NOT include an configuration files or extra folders that your IDE generates. (If you are working with a partner name the folder LASTNAME_LASTNAME_DLL before zipping.)

If any of your files or functions are named incorrectly or do not compile you may receive deductions.

 

Academic Integrity reminder:

You should be creating your own original work.

You may discuss topics with friends in human language. If you share code you can share no more than FOUR lines of code with a classmate. If you look at code online you should copy no more than 2-4 lines of code. I recommend citing your source to show me that you used a resource and did not copy too much.

You may work with the PI and tutors to receive help and have someone help debug your code. Just make sure that any code you create has your personal input and you understand it. (Adding comment with explanations at the time will help with this!!)

You may of course work with me but you should still only put something into your code once you understand what it does. (Adding comment with explanations at the time will help with this!!)

 

Grading Rubric:

Grading Rubric
Grade Area	Grade based on:
insertFirst	Code implements insert first functionality with O(1) efficiency
Code supports insert on null list
Code correctly updates last pointer
Keeps count accurate
Keeps all node connections correct
insertLast	Code implements insert last functionality with O(1) efficiency
Code supports insert on null list
Code correctly updates last pointer
Keeps count accurate
Keeps all node connections correct
insertNode	Code correctly inserts at appropriate index
Code supports insert on first/last index and null list
Keeps count accurate
Keeps all node connections correct
Code checks for illegal indices and provides message with reasonable level of information to register the error
deleteNode	Code correctly removes item from the middle of the list
Code handles deletion from first/last node and deletion of only element
Code provides reasonable feedback for element not in list or trying to delete from null list
Functionality	Based on test cases passed
Errors / Feedback	Errors should be printed for: Attempts do delete or insert at invalid index should have error message. Attempts to delete an item that isn't in the list. Attempts to delete on an empty list.
Readability	Proper level of relevant comments, good use of variables and variable naming
Submission/Compilation	Points WILL be deducted for incorrect names of files, file structures, function names, etc.
Rubric
Doubly Linked List
Doubly Linked List
Criteria	Ratings	Pts
This criterion is linked to a Learning OutcomeInsert beg & end
20 pts
Full Marks
0 pts
No Marks
20 pts
This criterion is linked to a Learning OutcomeInsert at index
20 pts
Full Marks
0 pts
No Marks
20 pts
This criterion is linked to a Learning OutcomeDelete Node
20 pts
Full Marks
0 pts
No Marks
20 pts
This criterion is linked to a Learning OutcomeFunctionality
10 pts
Full Marks
0 pts
No Marks
10 pts
This criterion is linked to a Learning OutcomeReadability
10 pts
Full Marks
0 pts
No Marks
10 pts
Total Points: 80
