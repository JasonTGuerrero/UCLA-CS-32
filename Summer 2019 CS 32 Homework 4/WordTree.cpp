//
//  WordTree.cpp
//  Summer 2019 CS 32 HW4
//
//  Created by Jason Guerrero on 8/12/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "WordTree.h"

void Print(WordNode* cur, ostream &out);

// copy constructor helper function
void WordTree::Copy(WordNode* &cur, WordNode* &copy)
{
    if (cur == nullptr)
        return;

    if (cur != nullptr)
    {
        copy = new WordNode;
        copy->m_data = cur->m_data;
        copy->m_key = cur->m_key;
        copy->m_left = nullptr;
        copy->m_right = nullptr;
    }

    Copy(cur->m_left, copy->m_left);
    Copy(cur->m_right, copy->m_right);
}



WordTree::WordTree(const WordTree& rhs)
{
   if (rhs.root == nullptr)
       root = nullptr;
    
   else
   {

       root = new WordNode;
       root->m_data = rhs.root->m_data;
       root->m_key = rhs.root->m_key;
       WordNode* copy = root;
       WordNode* cur = rhs.root;
       
       Copy(cur->m_left, copy->m_left);
       Copy(cur->m_right, copy->m_right);
   }
}

const WordTree& WordTree::operator=(const WordTree& rhs)
{
    if (this != &rhs)
    {
        if (rhs.root == nullptr)
            root = nullptr;
        else {
        FreeTree(this->root);
        root = new WordNode;
        root->m_data = rhs.root->m_data;
        root->m_key = rhs.root->m_key;
        WordNode* copy = root;
        WordNode* cur = rhs.root;
        
        Copy(cur->m_left, copy->m_left);
        Copy(cur->m_right, copy->m_right);
        }
    }
    
    return *this;
}

void WordTree::add(IType v)
{
    if (root == nullptr)
    {
        root = new WordNode(v);
        return;
    }
    
    WordNode* cur = root;
    while(true)
    {
        if (v == cur->m_data) {
            cur->m_key += 1;
            return;
        }
        
        if (v < cur->m_data)
        {
            if (cur->m_left != nullptr )
            {
                cur = cur->m_left;
            }
            
            else
            {
                cur->m_left = new WordNode(v);
                return;
            }
        }
        
        else if (v > cur->m_data)
        {
            if (cur->m_right != nullptr)
            {
                cur = cur->m_right;
            }
            
            else
            {
                cur->m_right = new WordNode(v);
                return;
            }
        }
    }
}

// distinctWords helper function
int WordTree::distinctCount(WordNode* cur, int& count) const
{
    if (cur == nullptr)
        return count;
    else
    {
        count += 1;
        distinctCount(cur->m_left, count);
        distinctCount(cur->m_right, count);
    }
    
    return count;
}

int WordTree::distinctWords() const
{
    int count = 0;
    
    if (root == nullptr)
        return 0;
    
    return distinctCount(root, count);
}



// totalWords helper function
int WordTree::Count(WordNode* cur, int& count) const
{
    if (cur == nullptr)
        return count;
    else
    {
        count += cur->m_key;
        Count(cur->m_left, count);
        Count(cur->m_right, count);
    }
    
    return count;
}



int WordTree::totalWords() const
{
    int count = 0;
    
    if (root == nullptr)
        return 0;
    
    return Count(root, count);
}


// Destructor helper function
void WordTree::FreeTree(WordNode* cur)
{
    if (cur == nullptr)
        return;
    
    FreeTree(cur->m_left);
    FreeTree(cur->m_right);
    
    delete cur;
}

WordTree::~WordTree()
{
    FreeTree(root);
}

ostream& operator<<(ostream &out, const WordTree& rhs)
{
    Print(rhs.root, out);
    return out;
}

// output operator overload helper function
void Print(WordNode* cur, ostream &out)
{
    if (cur == nullptr)
        return;
    
    Print(cur->m_left, out);
    
    out << cur->m_data << " " << cur->m_key << endl;
    
    Print(cur->m_right, out);
}
