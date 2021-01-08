//
//  PokemonStatCalculator.hpp
//  Review
//
//  Created by Philip Nguyen on 1/6/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#ifndef PokemonStatCalculator_hpp
#define PokemonStatCalculator_hpp

#include <stdio.h>

enum Pokeball {
    
};

int captureRateG4(int, int, int, float, float);
int shakeProbability(int);
bool shakeCheck();
bool catchAttempt(int, int, int, float, float);

#endif /* PokemonStatCalculator_hpp */
