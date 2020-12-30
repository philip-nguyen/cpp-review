//
//  skunk.hpp
//  Review
//
//  Created by Philip Nguyen on 12/29/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#ifndef skunk_hpp
#define skunk_hpp

#include <stdio.h>
#include <string>

class Dice {
    int die1, die2;
public:
    Dice();
    int roll();
};

class Player {
    std::string name;
    int rollsPerTurn;
    int points;
public:
    Player(std::string, int);
    int takeTurn(Dice);
    bool declareWinner();
};

#endif /* skunk_hpp */
