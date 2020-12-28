//
//  main.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <iostream>
#include <iterator>
#include "binarySearch.hpp"
#include "linkedlist.hpp"
#include "input.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Node* n = nullptr;
    Node* one = new Node("Nicole", 15);
    Node* two = new Node("EJ", 13);
    
    n = new Node("Philip", 14);
    n->appendToTail(n, one);
    n->appendToTail(n, two);
    
    std::cout << printList1(n);
    
    return 0;
}




