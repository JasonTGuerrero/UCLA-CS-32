//
//  LinkedList.cpp
//  CS 32 Summer 2019 HW1
//
//  Created by Jason Guerrero on 7/6/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "LinkedList.h"
using std::cout;
using std::endl;


LinkedList::~LinkedList()
{
    Node* p = head;         // start at the beginning of the list
    while (p != nullptr)    // traverse
    {
        Node *q = p->next;  // point to the next node
        delete p;           // delete current node
        p = q;              // make next current
    }
}


LinkedList::LinkedList(const LinkedList& rhs)
{
    if (rhs.head == nullptr)              // if rhs is empty, just set this list to be empty too
        head = nullptr;
    
    else {
        Node* p = new Node;               // allocate a new node
        p->value = rhs.head->value;       // give it the value of the first node in the existing list
        head = p;                         // have our copy's head point to the first copied node
        Node* q = rhs.head->next;         // start keeping track of the next node in the existing list
        
        while (q != nullptr) // traverse the existing list
        {
            Node* copy = new Node;      // allocate the next new copy
            copy->value = q->value;     // give it the current existing node's value
            p->next = copy;             // attach it to the end of the copied list
            q = q->next;                // increment to the next node in existing list
            p = p->next;                // increment to the next node in the copied list
        }
        p->next = nullptr;              // we are done copying, assign copied list's last node's next pointer to nullptr
    }
}


void LinkedList::insertToFront(const ItemType &val)
{
    Node* p = new Node;  // create a new node
    p->value = val;      // give it the value we are inserting
    p->next = head;      // put the new node at the front of the list
    head = p;            // have the head pointer make it the first item in the list
}

void LinkedList::printList() const
{
    if (head == nullptr)            // if the list is empty, nothing to print
        return;
    
    Node* p = head;                 // point at the front of the list
    while (p != nullptr) {          // traverse
        cout << p->value << " ";    // output value
        p = p->next;                // move on to the next node
    }
    cout << endl;
    return;
}

LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if (rhs.head == nullptr)
    {
        head = nullptr;         // if the rhs list is empty. make this list an empty list
        return *this;
    }
    
    
    if (this != &rhs)           // if we are assigning this to itself don't execute if-statement just return this list
    {
        Node* p = head;         // start at the beginning of the list
        while (p != nullptr)    // traverse
        {
            Node *r = p->next;  // point to the next node
            delete p;           // delete current node
            p = r;              // make next current
        }

        Node* s = new Node;             // now essentially do what copy constructor does
        head = s;
        head->value = rhs.head->value;
        Node* q = rhs.head->next;

        while (q != nullptr)
        {
            Node* copy = new Node;
            copy->value = q->value;
            s->next = copy;
            q = q->next;
            s = s->next;
        }
        s->next = nullptr;
    }
    
    return *this;
}

bool LinkedList::get(int i, ItemType& item) const
{
    int j = 0;                  // initialize starting index
    Node* p = head;             // point to first item in list

    while (p != nullptr)        // traverse list
    {
        if (i == j)             // when we have found position i
        {
            item = p->value;    // give item the node's value at position i
            return true;
        }
        p = p->next;            // move forward if we haven't found position i
        j++;
    }
    return false;               // return false if position i was not found
}

void LinkedList::reverseList()
{
    if (head == nullptr)            // if list empty, nothing to reverse
        return;
    
    
    int count = 0;                                      // count the items in the list
    for (Node* p = head; p != nullptr; p = p->next)
        count++;
    
    // ItemType items[count];                              // create an area of size count
    ItemType* items = new ItemType[count];
    
    int j = 0;
    for (Node* r = head; r != nullptr; r = r->next)     // put the values of the list into the array
    {
        items[j] = r->value;
        j++;
    }
    
    Node* q = head;                                     // point at the beginning of the list
    int i = count - 1;                                  // start from the end of the array
    while ( i >= 0)
    {                                           // give the list the array's item value starting from the end of the array
        q->value = items[i];
        q = q->next;                            // move forward in the list
        i--;                                    // move backward in the array
    }
    
    delete [] items;
}

void LinkedList::append(const LinkedList &other)
{
    if (other.head == nullptr)                                // if other list is empty, nothing to append
        return;
    
    Node* p;
    for (p = head; p->next != nullptr; p = p->next)     // point to the last node in this list
        ;
    
    Node* q;
    for (q = other.head; q != nullptr; q = q->next)     // traverse the other list
    {
        Node* append = new Node;                        // allocate a node
        append->value = q->value;                       // give it the other list's node's value
        p->next = append;                               // have this list's last node's next pointer point to append
        p = append;                                     // have p point to the appended node since it is now the last node
    }
    p->next = nullptr;                                  // when we are done, make the last node's next pointer nullptr
}

int LinkedList::size() const
{
    int count = 0;          // get ready to count the items
    Node* p = head;         // start at the first node
    while(p != nullptr)     // start counting
    {
        count++;
        p = p->next;
    }
    
    return count;           // return the total count
}



void LinkedList::swap(LinkedList &other)
{
    Node* temp = head;
    head = other.head;
    other.head = temp;
    temp = nullptr;
}

void LinkedList::printReverse() const
{
    if (head == nullptr)                                    // if the list is empty, nothing to print
        return;
    
    int count = 0;
    
    for (Node* p = head; p != nullptr; p = p->next)         // count the items in the list
        count++;
    
    // ItemType items[count];
    ItemType* items = new ItemType[count];                  // dynamically allocate an array of size count
    
    Node* p = head;                                         // starting from the end of the array
    for (int i = count - 1; i >= 0; i--)                    // copy the values from the list into the array from the start of
    {                                                       // the list
        items[i] = p->value;
        p = p->next;
    }
    
    for (int j = 0; j < count; j++)                         // now output the elements in the array
        cout << items[j] << " ";
    
    cout << endl;
    
    delete [] items;
}
