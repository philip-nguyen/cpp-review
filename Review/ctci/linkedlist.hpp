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

    Node(std::string n, int d);
    void appendToTail(Node* head, Node* n);
    
    std::string getName() { return name; }
    int getId() { return id; }
};

std::string printList1(Node*);

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