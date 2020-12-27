//
//  main.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <iostream>
#include "binarySearch.hpp"

// Forward Declarations
void printFactors(int);
int getInteger();

int main(int argc, const char * argv[]) {
    // insert code here...
    int number{ getInteger() };
    int array[]{ 1, 2, 5, 8, 9, 12, 15, 16, 17, 38, 40, 45, 54, 55, 60};
    
    printFactors(number);
    std::cout << "index of " << number << " is: " << binarySearch(array, 15, number) << '\n';
    return 0;
}

void printFactors(int num) {
    int x{1};
    while(x <= num) {
        if(num % x == 0)
            std::cout << x << std::endl;
        x++;
    }
}
