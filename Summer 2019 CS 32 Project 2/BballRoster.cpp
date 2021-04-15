//
//  BBallRoster.cpp
//  CS 32 Summer 2019 Project 2
//
//  Created by Jason Guerrero on 7/12/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.

#include "BballRoster.h"

BballRoster::BballRoster()              // create an empty list
{
    head = nullptr;
    tail = nullptr;
}

BballRoster::~BballRoster()            // destroy the list
{
    Node* p = head;
    while (p != nullptr)
    {
        Node* q = p->next;
        delete p;
        p = q;
    }
}

BballRoster::BballRoster(const BballRoster& rhs)
{
    if (rhs.head == nullptr && rhs.tail == nullptr)         // if rhs is empty, create an empty list
    {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = new Node;                            // copy the first node
        head->value = rhs.head->value;
        head->First = rhs.head->First;
        head->Last = rhs.head->Last;
        Node* q = head;
        Node* p = rhs.head->next;
        while(p != nullptr)                        // copy the rest of the nodes
        {
            q->next = new Node;
            q->next->value = p->value;
            q->next->First = p->First;
            q->next->Last = p->Last;
            q->next->next = nullptr;
            q->next->prev = q;
            p = p->next;
            q = q->next;
        }
        head->prev = nullptr;
    }
}

BballRoster& BballRoster::operator=(const BballRoster& rhs)
{
    if (rhs.head == nullptr && rhs.tail == nullptr)         // if rhs is empty, make this list empty
    {
        head = nullptr;
        tail = nullptr;
        return *this;
    }
    
    if (this != &rhs)                                   // check if we are reassigning this list to itself
    {
        Node* p = head;
        while (p != nullptr)
        {
            Node* q = p->next;
            delete p;
            p = q;
        }                                           // get rid of existing elements
        head = new Node;                            // start assigning this list to rhs list
        head->value = rhs.head->value;
        head->First = rhs.head->First;
        head->Last = rhs.head->Last;
        Node* q = head;
        Node* r = rhs.head->next;
        while (r != nullptr)
        {
            q->next = new Node;
            q->next->value = r->value;
            q->next->First = r->First;
            q->next->Last = r->Last;
            q->next->next = nullptr;
            q->next->prev = q;
            r = r->next;
            q = q->next;
        }
        head->prev = nullptr;
    }
    return *this;
}

int BballRoster::howManyPlayers() const
{
    int count = 0;
    for (Node* p = head; p != nullptr; p = p->next)         // count how many players
        count++;
    
    return count;   // return the count
}

bool BballRoster::rosterEmpty() const
{
    return (howManyPlayers() == 0);         // return this truth value
}

bool BballRoster::signPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value)
{
    if (head == nullptr && tail == nullptr)         // if this list is empty, just make it the first node
    {
        head = new Node;
        head->First = firstName;
        head->Last = lastName;
        head->value = value;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        return true;
    }

    for (Node* p = head; p != nullptr; p = p->next)
    {
        if (lastName < p->Last)         // if lastName comes before p->Last alphabetically
        {
            Node* q = new Node;         // make the insertion before p's node
            q->First = firstName;
            q->Last = lastName;
            q->value = value;
            q->next = p;
            q->prev = p->prev;
            if(q->prev != nullptr)
                q->prev->next = q;
            else
                head = q;
            p->prev = q;
            
            return true;
        }
        
        else if (lastName == p->Last)           // if the last names are the same, start comparing first names
        {
            if (firstName > p->First)    // if the first name is further down then p->first then jump to the next iteration
            {
                continue;
//                Node* q = new Node;
//                q->First = firstName;
//                q->Last = lastName;
//                q->value = value;
//                q->next = p->next;
//                q->prev = p;
//                q->next->prev = q;
//                q->prev->next = p;
//                return true;
            }
            
            else if (firstName == p->First)     // if last AND first names are the same, then spec says return false
                return false;
            
            else if (firstName < p->First)      // once we've found where p->first comes later alphabetically
            {
                Node* q = new Node;             // insert our new player right before p
                q->First = firstName;
                q->Last = lastName;
                q->value = value;
                q->next = p;
                q->prev = p->prev;
                q->prev->next = q;
                p->prev = q;
                
                return true;
            }
        }
//        else if (lastName < p->Last)
//        {
//            Node* q = new Node;
//            q->First = firstName;
//            q->Last = lastName;
//            q->value = value;
//            q->prev = p->prev;
//            p->prev = q;
//            q->next = p;
//
//            if (q->prev == nullptr)
//                head = q;
//
//            return true;
//        }
    }
    
    Node* s = new Node;         // if we haven't met any of the above cases, then the only other case would be to insert at the
    s->value = value;           // end of the roster
    s->First = firstName;
    s->Last = lastName;
    tail->next = s;
    s->prev = tail;
    tail = s;
    tail->next = nullptr;
    
    return true;
}


bool BballRoster::resignPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value)
{
    for (Node* p = head; p != nullptr; p = p->next)
    {
        if (firstName == p->First && lastName == p->Last)
        {
            p->value = value;
            return true;
        }
    }
    return false;
}

bool BballRoster::signOrResign(const std::string& firstName, const std::string& lastName, const SomeType& value)
{
    for (Node* p = head; p != nullptr; p = p->next)
    {
        if (firstName == p->First && lastName == p->Last)
        {
            p->value = value;
            return true;
        }
    }
    
    if (head == nullptr && tail == nullptr)         // if this list is empty, just make it the first node
    {
        head = new Node;
        head->First = firstName;
        head->Last = lastName;
        head->value = value;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        return true;
    }
    
    for (Node* p = head; p != nullptr; p = p->next)
    {
        if (lastName < p->Last)         // if lastName comes before p->Last alphabetically
        {
            Node* q = new Node;         // make the insertion before p's node
            q->First = firstName;
            q->Last = lastName;
            q->value = value;
            q->next = p;
            q->prev = p->prev;
            if(q->prev != nullptr)
                q->prev->next = q;
            else
                head = q;
            p->prev = q;
            
            return true;
        }
        
        else if (lastName == p->Last)           // if the last names are the same, start comparing first names
        {
            if (firstName > p->First)    // if the first name is further down then p->first then jump to the next iteration
                continue;
            
            else if (firstName == p->First)     // if last AND first names are the same, then spec says return false
                return false;
            
            else if (firstName < p->First)      // once we've found where p->first comes later alphabetically
            {
                Node* q = new Node;             // insert our new player right before p
                q->First = firstName;
                q->Last = lastName;
                q->value = value;
                q->next = p;
                q->prev = p->prev;
                q->prev->next = q;
                p->prev = q;
                
                return true;
            }
        }
    }
    
    Node* s = new Node;         // if we haven't met any of the above cases, then the only other case would be to insert at the
    s->value = value;           // end of the roster
    s->First = firstName;
    s->Last = lastName;
    tail->next = s;
    s->prev = tail;
    tail = s;
    tail->next = nullptr;
    
    return true;
}

bool BballRoster::renouncePlayer(const std::string& firstName, const std::string& lastName)
{
    for (Node* p = head; p != nullptr; p = p->next)
    {
        if (firstName == p->First && lastName == p->Last)       // if we've found the player
        {
            if (p->next == nullptr && p->prev == nullptr)       // if its just one player in the list
            {
                delete p;                                       // make the list empty
                head = nullptr;
                tail = nullptr;
                return true;
            }
            
            if (head == p)                                      // if the player is at the front of the list
            {
                p->next->prev = nullptr;
                head = p->next;
                p->next = nullptr;
                delete p;
                return true;
            }
            
            if (tail == p)                                      // if the player is at the back of the list
            {
                p->prev->next = nullptr;
                tail = p->prev;
                p->prev = nullptr;
                delete p;
                return true;
            }
            
            else                                                // if the player is somewhere in the middle of the list
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                p->next = p->prev = nullptr;
                delete p;
                return true;
            }
        }
    }
    return false;
}

bool BballRoster::playerOnRoster(const std::string& firstName, const std::string& lastName) const
{
    for (Node* p = head; p != nullptr; p = p->next)     // loop through roster
    {
        if ( p->First == firstName && p->Last == lastName)      // we've found our player
            return true;
    }
    
    return false;                       // we did not find our player
}

bool BballRoster::lookupPlayer(const std::string& firstName, const std::string& lastName, SomeType& value) const
{
    for (Node* p = head; p != nullptr; p = p->next)         // loop through the roster
    {
        if (p->First == firstName && p->Last == lastName)   // when we've found the player we were looking for
        {
            value = p->value;                               // set value equal to p->value and return true
            return true;
        }
    }
    return false;                                           // we did not find our player, return false
}



bool BballRoster::choosePlayer(int i, std::string& firstName, std::string& lastName, SomeType& value) const
{
    int j = 0;                                      // start at index 0
    Node* p = head;
    while (p != nullptr && j < howManyPlayers())    // while we aren't at the end of the list
    {
        if (i == j)                                 // when we've found the player we wanted to choose
        {
            firstName = p->First;                   // choose the player
            lastName = p->Last;
            value = p->value;
            return true;
        }
        j++;
        p = p->next;
    }
    return false;                                   // we didn't find the player to choose
}

void BballRoster::swapRoster(BballRoster& other)
{
    Node* tempHead = head;
    Node* tempTail = tail;
    head = other.head;              // just swap head and tail pointers
    tail = other.tail;
    other.head = tempHead;
    other.tail = tempTail;
}

bool joinRosters(const BballRoster & bbOne,
                 const BballRoster & bbTwo,
                 BballRoster & bbJoined)
{
    bbJoined = bbOne;
    bool flag = true;
    
    for (int i = 0; i < bbTwo.howManyPlayers(); i++)
    {
        string f2;
        string l2;
        SomeType v2;
        string f1;
        string l1;
        SomeType v1;
        bbOne.choosePlayer(i, f1, l2, v1);
        
        if (bbOne.lookupPlayer(f2, l2, v2))
        {
            if (v2 == v1)
            {
                continue;
            }
            else
                flag = false;
        }
        else
            bbJoined.signPlayer(f2, l2, v2);
    }
    
    return flag;
}

void checkRoster (const std::string& fsearch,
                  const std::string& lsearch,
                  const BballRoster& bbOne,
                  BballRoster& bbResult)
{
    
}


void BballRoster::dump() const
{
    
}
