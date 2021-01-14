//
//  sort.cpp
//  Review
//
//  Created by Philip Nguyen on 1/12/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#include "sort.hpp"
#include <vector>

/**
 Mergesort algorithm
 @param arr an array of Comparable data
 */
template <class T>
void mergeSort(std::vector<T> arr) {
    // size of the current arr
    std::vector<T> tempArr(arr.size());
    mergeSort(arr, tempArr, 0, arr.size - 1);
}

/**
 Internal
 */
template <class T>
void mergeSort(std::vector<T> a, std::vector<T> b, int left, int right) {
    if(left < right) {
        int center = (left + right) / 2;
        mergeSort(a, b, left, center); // split the array in half
        mergeSort(a, b, center + 1, right);
    }
}

/**
 Internal method that merge two sorted halves of a subarray
 @param a an array of Comparables
 @param b
 */
template <class T>
void merge(std::vector<T> a, std::vector<T> tempArr, int left, int center, int right) {
    int leftEnd = right - 1;
    int tmpPos = left;
    int numElements = right - left + 1;
    
    // main loop
    //while(left <= leftEnd && right)
}
