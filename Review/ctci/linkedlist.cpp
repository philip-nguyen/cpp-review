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

/**
// LinkedList Class
LinkedList::LinkedList(Node n) {
    head = n;
}

void LinkedList::addNode(Node n) {
    Node temp{this->head};
    while(temp.next != nullptr) {
        temp = temp.next;
    }
    temp->next = n;
}

std::string LinkedList::printList() {
    std::string s{};
    Node temp{this->head};
    while(temp != nullptr) {
        s += "Name: " + temp->getName() + "\tID: " + std::to_string(temp->getId()) + "\n";
        temp = temp->next;
    }
    
    return s;
}

*/
