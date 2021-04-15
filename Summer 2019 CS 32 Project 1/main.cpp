//
//  main.cpp
//  Summer 2019 CS 32 Project 1
//
//  Created by Jason Guerrero on 6/24/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "Game.h"
#include <ctime>
#include <cstdlib>

int main()
{
    // Initialize the random number generator.  (You don't need to
    // understand how this works.)
    srand(static_cast<unsigned int>(time(0)));
    
    // Create a game
    // Use this instead to create a mini-game:   Game g(3, 3, 2);
    Game g(15, 18, 80);
    
    // Play the game
    g.play();
}
