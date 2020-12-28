//
//  input.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "input.h"

int getInteger()
{
    std::cout << "Enter an Integer: ";
    int x{};
    std::cin >> x;
    return x;
}

void printFactors(int num) {
    int x{1};
    while(x <= num) {
        if(num % x == 0)
            std::cout << x << std::endl;
        x++;
    }
}
