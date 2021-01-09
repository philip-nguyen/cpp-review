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
