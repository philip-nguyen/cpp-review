//
//  main.cpp
//  Review
//
//  Created by Philip Nguyen on 12/21/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <random>
#include "ctci/binarySearch.hpp"
#include "ctci/linkedlist.hpp"
#include "cis22b/Assignment1-shopping_list/assignment1.hpp"
#include "cis22b/Assignment7-skunk/skunk.hpp"
#include "input.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Node* n = nullptr;
    Node* one = new Node("Nicole", 15);
    Node* two = new Node("EJ", 13);
    Node* thr = new Node("Steven", 23);
    Node* f4r = new Node("Toto", 30);
    
    n = new Node("Philip", 14);
    n->appendToTail(n, one);
    n->appendToTail(n, two);
    n->appendToTail(n, thr);
    n->appendToTail(n, f4r);
    
    std::cout << printList1(n);
    std::cout << "Deleting a Node...\n";
    deleteMiddleNode(thr);
    std::cout << printList1(n);
    return 0;
}




