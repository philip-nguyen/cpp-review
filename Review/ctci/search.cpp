//
//  binarySearch.cpp
//  Review
//
//  Created by Philip Nguyen on 12/26/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include "search.hpp"

// Parameters are array pointer, array SIZE and key
int binarySearch(int arr[], int arraySize, int key) {
    // int size = sizeof(arr) / sizeof(arr[0]);
    int low{0}, high{arraySize - 1}, middle{arraySize / 2};
    while (low < high) {
        middle = (high + low) / 2;
        if(arr[middle] < key) {
            // move the low index above the middle
            low = middle + 1;
        }
        else if(arr[middle] > key)
            high = middle - 1;
        // move middle to the middle of new bounds
        else
            return middle;
    }
    // return found index
    return -1;
}
