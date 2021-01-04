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

void Node::appendToTail(Node* head, Node* n) {
    
    Node* l = head;
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

/** Sum list test
 
 */
