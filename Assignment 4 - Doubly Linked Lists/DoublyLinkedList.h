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
    newNode->next = this->head; 
    newNode->prev = NULL;

    // Update previous head node
    this->head->prev = newNode; // Supposed to tell previous head's prev variable to become newNode

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
    newNode->prev = this->tail;

    // Update previous tail node
    this->tail->next = newNode;

    // Update list's information
    this->tail = newNode;
    this->count += 1;
}

template <class Type>
void DoublyLinkedList<Type>::insertNode(const Type& newItem, int index){

    //TODO: Test this function
    // Supposed to insert node before index; would make newItem take the index in the updated list

    // Traverse to index
    NodeType<Type>* current = this->head;
    if (index <= this->count) { // Verify index is within list
        for (int i = 0; i != index; i++) {
            current = current->next;
        }
    }

    // Build new node
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->next = current;
    newNode->prev = current->prev;

    // Update surrounding nodes
    current->prev->next = newNode; // Supposed to tell old previous node to start pointing to new node
    current->prev = newNode; // In theory, disconnecting will be safe now

    // Update list's information
    this->count += 1;
}

template <class Type>
void DoublyLinkedList<Type>::deleteNode(const Type& deleteItem){

    //TODO: Test this function

    // Find deleteItem in list
    assert(!this->isEmptyList());
    NodeType<Type>* current = this->head;
    if (current->data == deleteItem) { // Edge case: If deleteItem is list head, update list head
        this->head = current->next;
    }
    else {
        while (current != NULL) { 
            if (current->data == deleteItem) {
                current->prev = current->next; 
                delete current; // If causes error, OK to delete; not part of assignment
                break;
            }
            current = current->next; 
        }
    }

    // Update list's information
    this->count -= 1;
}

#endif /* DoublyLinkedList_h */
