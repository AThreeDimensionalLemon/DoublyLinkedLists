//
//  DoublyLinkedList.h
//
//  Blank version of file for assignment
//
//  Created by Katz, Ariel on 2/14/23.
//  Completed by Liang, Eisig on 
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "ListType.h"
#include <assert.h>

using namespace std;

template <class Type>
class DoublyLinkedList: public ListType<Type> {
public:
    
    void print(bool forward) const ;
      //Function to output the data contained in each node.
      //If argument is true list prints forward
    // If forward is false list prints in reverse
    
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      // Returns true if searchItem is in the

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //newItem becomes head and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //newItem becomes tail and count is incremented by 1.
    
    void insertNode(const Type& newItem, int index);
      //Function to insert newItem at the given index.
    // If index is out of range print error
      //newItem becomes element at index and all other elements are shifted.
    // count is incremented by one.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list
      //               and count is decremented by 1.
    
};

template <class Type>
void DoublyLinkedList<Type>::print(bool forward) const
{
    NodeType<Type> *current; //pointer to traverse the list
    if (forward){
        current = this->head;    //start traversal from the head node
        while (current != NULL) //while more data to print
        {
            cout << current->data << " ";
            current = current->next;
        }
    } else {
        current = this->tail;    //start traversal from the tail node
        while (current != NULL) //while more data to print
        {
            cout << current->data << " ";
            current = current->prev;
        }
    }
    cout << endl;
}

template <class Type>
bool DoublyLinkedList<Type>::
                   search(const Type& searchItem) const
{
    NodeType<Type> *current; //pointer to traverse the list
    current = this->head; //start search at the beginning

    //as long as there is more to search
    //and the node hasn't been found - keep searching
    while (current != NULL )
        if (current->data == searchItem)
            return true;
        else{
            current = current->next; //step forward
        }
            
    return NULL;
}//end search

template <class Type>
void DoublyLinkedList<Type>::insertFirst(const Type& newItem){
    
    //TODO: Test this function

    // Build new node
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->prev = NULL;

    // Set next of new node
    if (this->head) { // Replace head
        newNode->next = this->head;
        this->head->prev = newNode; 
    }
    else if (this->tail) { // Set head

        // Traverse from tail to beginning
        NodeType<Type>* current = this->tail;
        while (current->prev != NULL) {
            current = current->prev;
        }

        newNode->next = current;
        current->prev = newNode;
    }
    else { // Start the list with head
        newNode->next = NULL;
    }

    // Update list's information
    this->head = newNode;
    this->count += 1;
}

template <class Type>
void DoublyLinkedList<Type>::insertLast(const Type& newItem){

    //TODO: Test this function

    // Build new node
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->next = NULL;

    // Set prev of new node
    if (this->tail) { // Replace tail
        newNode->prev = this->tail;
        this->tail->next = newNode;
    }
    else if (this->head) { // Set tail

        // Traverse from head to end
        NodeType<Type>* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }

        newNode->prev = current;
        current->next = newNode;
    }
    else { // Start the list with tail
        newNode->prev = NULL;
    }

    // Update list's information
    this->tail = newNode;
    this->count += 1;
}

template <class Type>
void DoublyLinkedList<Type>::insertNode(const Type& newItem, int index){

    //TODO: Test this function
    // Supposed to insert node before index; would make newItem take the index in the updated list

    if (this->count == 0 or index <= 0) { // Insert head
        DoublyLinkedList<Type>::insertFirst(newItem);
        if (index < 0) {
            cout << "Index was too small; inserted " << newItem << " as head instead." << endl;
        }
    }
    else if (index >= this->count) { // Insert tail
        DoublyLinkedList<Type>::insertLast(newItem);
        cout << "Index was too big; inserted " << newItem << " as tail instead." << endl;
    }
    else { // Insert into list

        // Traverse to index
        NodeType<Type>* current = this->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        // Build new node
        NodeType<Type>* newNode = new NodeType<Type>;
        newNode->data = newItem;
        newNode->next = current;
        newNode->prev = current->prev;

        // Update surrounding nodes
        current->prev->next = newNode; // Supposed to tell old previous node to start pointing to new node
        current->prev = newNode; // In theory, disconnecting will be safe now

        // Update list's information (other cases update with called functions)
        this->count += 1;
    }

}

template <class Type>
void DoublyLinkedList<Type>::deleteNode(const Type& deleteItem){

    //TODO: Test this function

    // Find deleteItem in list
    if (this->count == 0) {
        cout << "This list is empty; ignored execution." << endl;
    }
    else {
        NodeType<Type>* current = this->head;
        while (true) {

            if (current->data == deleteItem) { // Delete deleteItem if found

                if (deleteItem == this->head->data) { // If head, update head
                    current->next->prev = NULL;
                    this->head = current->next;
                }
                else if (deleteItem == this->tail->data) { // If tail, update tail
                    current->prev->next = NULL;
                    this->tail = current->prev;
                }
                else { // If middle of list, update surrounding nodes
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                }

                delete current; // If this causes errors, okay to delete

                this->count -= 1; // Update list's information
                break;
            }

            if (current->next == NULL) { // If deleteItem not found by end of list, break
                cout << deleteItem << " isn't in list; ignored execution." << endl;
                break;
            }

            current = current->next;
        }
    }
}

#endif /* DoublyLinkedList_h */
