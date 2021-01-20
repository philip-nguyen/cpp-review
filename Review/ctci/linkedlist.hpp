//
//  linkedlist.hpp
//  Review
//
//  Created by Philip Nguyen on 12/27/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
#include <string>
// LinkedList Node Class
class Node {
    std::string name;
    int id;

public:
    Node* next;

    Node();
    Node(std::string n, int d);
    void appendToTail(Node* n);
    
    std::string getName() { return name; }
    int getId() { return id; }
    
    void setName(std::string n){ name = n; }
    void setId(int i){ id = i; }
};

std::string printList1(Node*);
// Problem 2.2
void printKthtoLastNode(Node*, int, int&);
// Problem 2.3
void deleteMiddleNode(Node*);
// Problem 2.4
void partition(Node*, int);
// Problem 2.5.1
void sumList(Node*, Node*);
// Problem 2.7
void findIntersection(Node*, Node*);

Node* mergeTwoLists(Node*, Node*);
Node* deleteDuplicates(Node*);
/*
// LinkedList Class
class LinkedList {
    Node head;
    
public:
    LinkedList(Node n);
    
    void addNode(Node n);
    
    std::string printList();
};
 */
#endif /* linkedlist_hpp */
