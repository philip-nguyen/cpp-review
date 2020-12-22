//
//  main.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <iostream>

// Forward Declarations
void printFactors(int);
int getInteger();

int main(int argc, const char * argv[]) {
    // insert code here...
    int number{ getInteger() };
    
    std::cout << "Hello, World!\n";
    
    printFactors(number);
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
