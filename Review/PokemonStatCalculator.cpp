//
//  PokemonStatCalculator.cpp
//  Review
//
//  Created by Philip Nguyen on 1/6/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//
#include <math.h> // sqrt
#include <random> // random_device
#include <iostream>

#include "PokemonStatCalculator.hpp"

int captureRateG4(int hpMax, int hpCurrent, int captureRate, float ballRate, float status) {
    int a = (3 * hpMax - 2 * hpCurrent) * captureRate * ballRate;
    a = a / (3 * hpMax);
    a = a * status;
    
    return a;
}

int shakeProbability(int a) {
    int b = 1048560 / sqrt(sqrt(16711680 / a));
    return b;
}

bool shakeCheck(int b) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> bDistribution(0,65535);
    
    int check = bDistribution(generator);
    std::cout << "Check:\t" << check << "\tb:\t" << b << std::endl;
    if (check < b)
        return true;
    else
        return false;
}

bool catchAttempt(int hpMax, int hpCurrent, int captureRate, float ballRate, float status) {
    int a = captureRateG4(hpMax, hpCurrent, captureRate, ballRate, status);
    int b = shakeCheck(a);
    
    int shakes{0};
    int inBall = true;
    // shake checks
    while(shakes < 4 && inBall) {
        if(shakeCheck(b)) {
            shakes++;
            std::cout << "Shake!...\n";
        }
        else {
            inBall = false;
            std::cout << "They broke free!\n";
        }
    }
    // if it shakes three times and is successful the 4th
    if(shakes == 4 ) {
        std::cout << "Pokemon was caught!\n";
        return true;
    }
    return false;
}
