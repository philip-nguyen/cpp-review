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
#include "PokemonStatCalculator.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    bool catchPokemon = false;
    int times{0};
    while(!catchPokemon && times < 55) {
        catchPokemon = catchAttempt(155, 3, 3, 3.5f, 2);
        times++;
    }
    //std::cout << "Deleting a Node...\n";
    //deleteMiddleNode(thr);
    //std::cout << printList1(n);
    
    return 0;
}




