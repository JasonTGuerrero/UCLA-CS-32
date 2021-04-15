//
//  Arena.h
//  Summer 2019 CS 32 Project 1
//
//  Created by Jason Guerrero on 6/24/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#ifndef Arena_h
#define Arena_h

#include <string>
#include "globals.h"
#include "Before.h"

class Player;
class Robot;

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(std::string msg) const;
    Before& whatWasBefore();
    
    // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();
    
private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
    Before m_before;
};

#endif /* Arena_h */
