//
//  sort.hpp
//  Review
//
//  Created by Philip Nguyen on 1/12/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include <vector>

template <class T>
void mergeSort(std::vector<T>);

template <class T>
void mergeSort(std::vector<T>, std::vector<T>, int left, int right);

template <class T>
void merge(std::vector<T>, std::vector<T>, int, int, int);

#endif /* sort_hpp */
