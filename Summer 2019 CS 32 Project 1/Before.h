//
//  Before.h
//  Summer 2019 CS 32 Project 1
//
//  Created by Jason Guerrero on 6/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#ifndef Before_h
#define Before_h

#include "globals.h"


class Before
{
public:
    Before(int nRows, int nCols);
    bool keepTrack(int r, int c);
    void printWhatWasBefore() const;
    
private:
    int m_rows;
    int m_cols;
    char m_arena[MAXROWS][MAXCOLS];
};

#endif /* Before_h */
