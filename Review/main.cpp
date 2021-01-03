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
    Node* n = new Node("Philip", 1);
    Node* one = new Node("Nicole", 25);
    Node* two = new Node("EJ", 33);
    Node* thr = new Node("Steven", 3);
    Node* f4r = new Node("Toto", 5);
    Node* five = new Node("Apple", 17);
    Node* six = new Node("Intel", 8);
    Node* seven = new Node("Accuray", 20);
    
    n->appendToTail(n, one);
    n->appendToTail(n, two);
    n->appendToTail(n, thr);
    n->appendToTail(n, f4r);
    n->appendToTail(n, five);
    n->appendToTail(n, six);
    n->appendToTail(n, seven);
    
    std::cout << printList1(n);
    
    // needs a reference to this
    int x{0};
    printKthtoLastNode(n, 4, x);
    
    partition(n, 17);
    
    //std::cout << "Deleting a Node...\n";
    //deleteMiddleNode(thr);
    //std::cout << printList1(n);
    
    return 0;
}




