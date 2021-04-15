//
//  Game.h
//  Summer 2019 CS 32 Project 1
//
//  Created by Jason Guerrero on 6/24/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#ifndef Game_h
#define Game_h


class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
};

#endif /* Game_h */
