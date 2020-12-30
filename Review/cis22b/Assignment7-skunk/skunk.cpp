//
//  skunk.cpp
//  Review
//
//  Created by Philip Nguyen on 12/29/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include "skunk.hpp"
#include <iostream>
#include <string>
#include <random>
#include <time.h>       // for time function for different seed
#include <unistd.h>     // usleep


Dice::Dice(){}
/**
 Dice roll:
 1) If d1 != 1 AND d2 != 1, return sum (to be added)
 2) If d1 == 1 XOR d2 == 1, return 0 (to be added)
 3) If d1 == 1 AND d2 == 1, return -1 (a flag to zero out the score)
 */
int Dice::roll() {
    // initialize random seed
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,6);
    
    // Roll the dice
    die1 = distribution(generator);
    die2 = distribution(generator);
    
    
    if(die1 == 1 && die2 == 1) {
        std::cout << "You rolled a " << die1 << " and a " << die2 << ". That's a SKUNK!!! End of turn." << std::endl;
        return -1;
    }
    else if(die1 == 1 ^ die2 == 1) { // ^ is XOR
        std::cout << "You rolled a " << die1 << " and a " << die2 << ". That's 0" << std::endl;
        return 0;
    }
    else {
        std::cout << "You rolled a " << die1 << " and a " << die2 << ". That's " << die1 + die2 << std::endl;
        
        return die1 + die2;
    }
        
    
}

/**
 Player constructor
 with different roll counts per turn
 */
Player::Player(std::string n, int r) {
    name = n;
    rollsPerTurn = r;
    points = 0;
};

/**
 int takeTurn
 returns int points
 */
int Player::takeTurn(Dice d) {
    int dice{}, turnSum{}, rollNum{0};
    
    std::cout << name + ", it's your turn!\n";
    // while still have rollsPerTurn
    while(rollNum < rollsPerTurn) {
        rollNum++;
        dice = d.roll();
        // not 1 roll
        if(dice > 0) {
            turnSum += dice;
        }
        // single 1 roll
        else if(dice == 0) {
            rollNum = rollsPerTurn;
            turnSum = 0;
        }
        // double 1 roll
        else { // -1 return for SKUNK
            rollNum = rollsPerTurn;
            turnSum = 0;
        }
    }
    points += turnSum;
    std::cout << "Points for the turn = " << turnSum << ".\tTotal Points = " << points << std::endl;
    return points;
}

// Declare the winner and return true for gameOver
bool Player::declareWinner() {
    return true;
}


/**
 int main() {
    Player curly("Curly",1);
    Player larry("larry",2);
    Player moe("Moe",4);

    Dice dice;

    bool gameOver = false;

    while (!gameOver)
    {
        if      (curly.takeTurn(dice) >= 100) gameOver = curly.declareWinner();
        else if (larry.takeTurn(dice) >= 100) gameOver = larry.declareWinner();
        else if (moe.takeTurn(dice) >= 100)   gameOver = moe.declareWinner();
        else { cout << "----------------------------------------------\n";}
    }

    cout << "That's all folks!!!" << endl;
 
 }
 */
