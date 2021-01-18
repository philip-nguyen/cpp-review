//
//  hashSet.cpp
//  Review
//
//  Created by Philip Nguyen on 1/17/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#include "hashSet.hpp"
#include <unordered_set>
#include <unordered_map>

int singleNumber(std::vector<int>& nums) {
    std::unordered_set<int> mySet;
    
    for(int i = 0; i < nums.size(); i++) {
        // if the num is not part of the set yet
        if(mySet.find(nums[i]) == mySet.end()) {
            // add to the set
            mySet.insert(nums[i]);
        }
        // otherwise take it out of the set
        else {
            mySet.erase(nums[i]);
        }
        // the set should only consist of one value
        // after the loop is finished
    }
    
    // return the only element left in the set
    return *mySet.begin();
}

// Uses a hash map instead to keep track of
// numbers frequency more than twice (in then out)
int singleNumber2(std::vector<int>& nums) {
    std::unordered_map<int, int> myMap;
    
    for(int i = 0; i < nums.size(); i++) {
        // if num is not found
        std::unordered_map<int, int>::const_iterator got = myMap.find(nums[i]);
        if(got == myMap.end()) {
            // insert value with amount of times it
            // should appear again (twice more)
            myMap.insert({nums[i], 2});
        }
        // decrement and check if zero to remove
        else {
            myMap.at(nums[i]) -= 1;
            if(myMap.at(nums[i]) == 0) myMap.erase(nums[i]);
        }
    }
    return myMap.begin()->first;
}
