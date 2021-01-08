//
//  linkedlist.cpp
//  Review
//
//  Created by Philip Nguyen on 12/27/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include "linkedlist.hpp"
#include <string>
#include <iostream>
#include <math.h>

/** To test in main:
 Node* n = nullptr;
 Node* one = new Node("Nicole", 15);
 Node* two = new Node("EJ", 13);
 
 n = new Node("Philip", 14);
 n->appendToTail(n, one);
 n->appendToTail(n, two);
 
 std::cout << printList1(n);
 */

// LinkedList Node Class
Node::Node(std::string n, int d) {
    this->name = n;
    this->id = d;
    this->next = nullptr;
}

void Node::appendToTail(Node* n) {
    
    Node* l = this;
    while(l->next != nullptr) {
        l = l->next;
    }
    l->next = n;
}

// Non class function to print list
std::string printList1(Node* n) {
    std::string s{};
    while(n != nullptr) {
       s += "ID: " + std::to_string(n->getId()) + "\tName: " + n->getName() +"\n";
        n = n->next;
    }
    return s;
}

void deleteMiddleNode(Node* n) {
    if(n->next == nullptr)
        std::cout << "ERROR: This is the end node\n";
    // overwrite the next node's info to current node
    n->setId(n->next->getId());
    n->setName(n->next->getName());
    // omit next node
    n->next = n->next->next;
}

void printKthtoLastNode(Node* curr, int k, int& index) {
    if(curr != nullptr) {
        printKthtoLastNode(curr->next, k, index);
        index++;
        if(index == k)
            std::cout << curr->getName() << std::endl;
    }
}

// for all node with id < x put in left partition
// otherwise put in right partition
void partition(Node* curr, int x) {
    Node* leftPartitionHead = nullptr;
    Node* leftPartitionTail = nullptr;
    Node* rightPartitionHead = nullptr;
    Node* rightPartitionTail = nullptr;
    
    while(curr != nullptr) {
        // if curr->getId < x add to left partition
        //Node* next = curr->next;
        //curr->next = nullptr;
        if(curr->getId() < x) {
            if(leftPartitionHead == nullptr) {
                leftPartitionHead = curr;
                leftPartitionTail = leftPartitionHead;
            }
            else {
                leftPartitionTail->next = curr;
                leftPartitionTail = leftPartitionTail->next;
            }
        }
        // otherwise add to right partition
        else {
            if(rightPartitionHead == nullptr) {
                rightPartitionHead = curr;
                rightPartitionTail = rightPartitionHead;
            }
            else {
                rightPartitionTail->next = curr;
                rightPartitionTail = rightPartitionTail->next;
            }
            
        }
        curr = curr->next;
    }
    
    leftPartitionTail->next = rightPartitionHead;
    
    std::cout << printList1(leftPartitionHead) << std::endl;
}

void sumList(Node* n1, Node* n2) {
    int sum{0}, num1, num2;
    int place{0};
    
    while(n1 != nullptr || n2 != nullptr) {
        if(n1 != nullptr) {
            // get the number
            num1 = n1->getId();
            // traverse
            if (n1->next != nullptr) n1 = n1->next;
            else n1 = nullptr;
        }
        else num1 = 0;
        
        if(n2 != nullptr) {
            num2 = n2->getId();
            if (n2->next != nullptr) n2 = n2->next;
            else n2 = nullptr;
        }
        else num2 = 0;
        
        sum += (num1 + num2) * pow(10, place);
        // increment to the next digit place
        place++;
        
        
    }
    
    std::cout << "Sum: " << sum << std::endl;
}
// Example code
/**
 Node* n = new Node("Philip", 1);
 Node* one = new Node("Nicole", 25);
 Node* two = new Node("EJ", 33);
 Node* thr = new Node("Steven", 3);
 Node* f4r = new Node("Toto", 5);
 Node* five = new Node("Apple", 17);
 Node* six = new Node("Intel", 8);
 Node* seven = new Node("Accuray", 20);
 
 n->appendToTail(one);
 n->appendToTail(two);
 n->appendToTail(thr);
 n->appendToTail(f4r);
 n->appendToTail(five);
 n->appendToTail(six);
 n->appendToTail(seven);
 
 std::cout << printList1(n);
 
 // needs a reference to this
 int x{0};
 printKthtoLastNode(n, 4, x);
 
 partition(n, 17);
 */


// Sum List Example
/** Sum list test
Node *n11 = new Node("", 7);
Node *n12 = new Node("", 1);
Node *n13 = new Node("", 6);

Node *n21 = new Node("", 5);
Node *n22 = new Node("", 9);
Node *n23 = new Node("", 2);
Node *n24 = new Node("", 1);

n->appendToTail(n11, n12);
n->appendToTail(n11, n13);

n->appendToTail(n21, n22);
n->appendToTail(n21, n23);
n->appendToTail(n21, n24);

sumList(n11, n21);
 */

void findIntersection(Node* n1, Node* n2) {
    while(n1 != n2 && n1 != nullptr && n2 != nullptr) {
        n1 = n1->next;
        n2 = n2->next;
    }
    if(n1 == n2) {
        std::cout << "Intersection found!\n";
        std::cout << n1->getName() << std::endl;
    }
    else
        std::cout << "No intersection found" << std::endl;
}
// find Intersection Example
/**
 Node* n1 = new Node("", 2);
 Node* n2 = new Node("", 2);
 Node* n3 = new Node("", 2);
 
 n1->appendToTail(n3);
 n2->appendToTail(n3);
 findIntersection(n1, n2);
 */
