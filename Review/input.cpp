//
//  input.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
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

int lengthLongestPath(std::string input) {
    // input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
    std::stringstream ss(input);
    std::vector<int> pathLengths(100, 0); // 100 int vectors of 0
    std::string tempToken;
    
    int maxLength{0};
    // get the tokens with getline
    while(getline(ss, tempToken, '\n')) {
        //tokens.push_back(tempToken);
        int depth{0};
        // while depth < token size; increment depth by counting tabs
        while(depth < tempToken.size() && tempToken[depth] == '\t') depth++;
        // depth == slashes
        // get the file/dir path after the tab
        std::string subpath = tempToken.substr(depth);
        // store the length of the subpath in the dth index
        pathLengths[depth] = subpath.size();
        // check if there is a '.' to check for files
        if(subpath.find('.') != std::string::npos) {
            int clen = 0;
            for(int k = 0; k <= depth; k++) clen += pathLengths[k];
            maxLength = std::max(maxLength, clen + depth); // add d (the slashes)
        }
    }
    
    return maxLength;

}

// condition: CANNOT directly convert to integers
std::string addStrings(std::string num1, std::string num2) {
    
    std::string sum = "";
    int carry{0};
    
    // check for bounds
    if(num1.length() < 5100 && num2.length() < 5100) {
        int longer = num1.length() >= num2.length() ? num1.length() : num2.length();
        int len1 = num1.length();
        int len2 = num2.length();
        for (int i = 1; i <= longer; i++) {
            // iterate through the string of numbers BACKWARDS
            // check if the length - index is within the string's bounds
            // convert each character to int
            // substract ascii value of '0' to get int value
            int a = (len1 - i >= 0) ? ((int)(num1[len1 - i] - '0')) : 0;
            int b = (len2 - i >= 0) ? ((int)(num2[len2 - i] - '0')) : 0;
            // summate and concatenate to a string
            if(a + b + carry >= 10) {
                sum = std::to_string(a + b + carry - 10) + sum;
                carry = 1;
            }
            else {
                sum = std::to_string(a + b + carry) + sum;
                carry = 0;
            }
            
        }
        
    }
    
    return (carry) ? "1" + sum : sum;
}

/**
 Two Sum
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
std::vector<int> twoSum(std::vector<int> & nums, int target) {
    // map is used to keep a set of factors
    std::unordered_map<int, int> mySet;
    // return a vector with the appropriate indexes
    std::vector<int> ret;
    
    for(int i = 0; i < nums.size(); i++) {
        int numberToFind = target - nums[i];
        
        // if the set has the other number
        if(mySet.find(numberToFind) != mySet.end()) {
            // push value from key = numberToFind
            ret.push_back(mySet[numberToFind]);
            // push the other current index value
            ret.push_back(i);
            return ret;
        }
        // add it to the set
        // where key = num 1
        // value = index #
        mySet[nums[i]] = i;
    }
    
    return ret;
}

/**
 Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.
 
 It can be 1 insert/delete or 1 replace
 */
bool oneEditDistance(std::string s, std::string t) {
    int m = s.size(), n = t.size();
    if (m > n) {
        // run the function again with the shorter term in param s
        return oneEditDistance(t, s);
    }
    for (int i = 0; i < m; i++) {
        // if the characters are not equal
        if (s[i] != t[i]) {
            // if the lengths are equal, check if the rest is equal
            if (m == n) {
                return s.substr(i + 1) == t.substr(i + 1);
            }
            // check if the rest of the substrings are equal
            return s.substr(i) == t.substr(i + 1);
        }
    }
    // on the special case that the character is at the end
    return m + 1 == n;
}

/**
 Swap two numbers without using any temp variable
 */
void swap(int &a, int &b) {
    a = a + b;
    b = a - b; // (a + b) - b = a
    a = a - b; // (a + b) - (a) = b
}
