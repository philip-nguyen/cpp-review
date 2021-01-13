//
//  sort.cpp
//  Review
//
//  Created by Philip Nguyen on 1/12/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#include "sort.hpp"
#include <vector>

template <class T>
void mergeSort(std::vector<T> arr) {
    // size of the current arr
    std::vector<T> tempArr(arr.size());
    mergeSort(arr, tempArr, 0, arr.size - 1);
}

template <class T>
void mergeSort(std::vector<T> a, std::vector<T> b, int left, int right) {
    
}
