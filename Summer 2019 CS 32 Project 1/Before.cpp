//
//  Before.cpp
//  Summer 2019 CS 32 Project 1
//
//  Created by Jason Guerrero on 6/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "Before.h"
#include "globals.h"
#include <iostream>
using std::cout;
using std::endl;

Before::Before(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            m_arena[i][j] = '.';
        }
    }
}



bool Before::keepTrack(int r, int c)
{
    if (r < 1 || c < 1 || r > MAXROWS || c > MAXCOLS) {
        return false;
    }
    
    if (m_arena[r-1][c-1] == '.') {
        m_arena[r-1][c-1] = 'A';
    }
    else if (m_arena[r-1][c-1] < 'Z') {
        m_arena[r-1][c-1]++;
    }
    else if (m_arena[r-1][c-1] >= 'Z') {
        m_arena[r-1][c-1] = 'Z';
    }
    
    return true;
}



void Before::printWhatWasBefore() const
{
    
    clearScreen();
    
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            cout << m_arena[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
