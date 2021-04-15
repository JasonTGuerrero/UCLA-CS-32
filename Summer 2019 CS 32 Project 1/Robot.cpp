//
//  Robot.cpp
//  Summer 2019 CS 32 Project 1
//
//  Created by Jason Guerrero on 6/24/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "Robot.h"
#include "globals.h"
#include "Arena.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "***** Robot created with invalid coordinates (" << r << ","
        << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_health = INITIAL_ROBOT_HEALTH;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
    return m_col;
}

void Robot::move()
{
    // Attempt to move in a random direction; if we can't move, don't move
    switch (rand() % 4)
    {
        case UP:     if (m_row > 1)               m_row--; break;
        case DOWN:   if (m_row < m_arena->rows()) m_row++; break;
        case LEFT:   if (m_col > 1)               m_col--; break;
        case RIGHT:  if (m_col < m_arena->cols()) m_col++; break;
    }
}

bool Robot::takeDamageAndLive()  // return true if not yet dead
{
    if (m_health > 0)
        m_health--;
    return m_health > 0;
}
