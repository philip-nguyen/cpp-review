//
//  hashSet.cpp
//  Review
//
//  Created by Philip Nguyen on 1/17/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#include "hashSet.hpp"
#include <unordered_set>

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
