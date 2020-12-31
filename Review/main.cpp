//
//  main.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <random>
#include "ctci/binarySearch.hpp"
#include "ctci/linkedlist.hpp"
#include "cis22b/Assignment1-shopping_list/assignment1.hpp"
#include "cis22b/Assignment7-skunk/skunk.hpp"
#include "input.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Assignment 1
    // std::cout << "Assignment 1...\n";
    // fileOutput();
    
    
    // Assignment 7
    std::cout << "Assignment 7...\n";
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
        else { std::cout << "----------------------------------------------\n";}
    }

    std::cout << "That's all folks!!!" << std::endl;
    
    return 0;
}




