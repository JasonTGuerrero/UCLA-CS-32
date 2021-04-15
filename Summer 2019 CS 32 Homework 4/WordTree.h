//
//  WordTree.h
//  Summer 2019 CS 32 HW4
//
//  Created by Jason Guerrero on 8/12/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#ifndef WordTree_h
#define WordTree_h

#include <iostream>
#include <string>
using namespace std;
typedef string IType;
struct WordNode
{
    WordNode(const IType &myVal)
    {
        m_data = myVal;
        m_left = m_right = nullptr;
        m_key = 1;
    }
    
    WordNode()
    {
        m_left = m_right = nullptr;
        m_key = 1;
    }
    
    int m_key;
    IType m_data;
    WordNode *m_left;
    WordNode *m_right;
    // You may add additional data members and member functions
    // in WordNode
};
class WordTree {
private:
    WordNode *root;
    void Copy(WordNode* &cur, WordNode* &copy);
    int Count(WordNode* cur, int& count) const;
    int distinctCount(WordNode* cur, int& count) const;
    void insert(const IType v);
    void FreeTree(WordNode* cur);
    
    
    
public:
    // default constructor
    WordTree() : root(nullptr) { };
    
    // copy constructor
    WordTree(const WordTree& rhs);
    
    // assignment operator
    const WordTree& operator=(const WordTree& rhs);
    
    // Inserts v into the WordTree
    void add(IType v);
    
    // Returns the number of distinct words / nodes
    int distinctWords() const;
    
    // Returns the total number of words inserted, including
    // duplicate values
    int totalWords() const;
    
    // Prints the LinkedList
    friend ostream& operator<<(ostream &out, const WordTree&
                               rhs);
    
    // Destroys all the dynamically allocated memory in the
    // tree
    ~WordTree();
};



#endif /* WordTree_h */

