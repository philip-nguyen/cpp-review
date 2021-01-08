//
//  stack.hpp
//  Review
//
//  Created by Philip Nguyen on 1/5/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <vector>

// Node
class StackNode {
public:
    StackNode* next;
    int data;
    StackNode* min;
    
    StackNode(int);
};

// Stack Implementation
class Stack {
public:
    StackNode* top;
    int size;
    
    Stack(StackNode* n) {
        top = n;
        size = 1;
    }
    
    StackNode* pop();
    void push(StackNode*);
    StackNode* peek();
    bool isEmpty();
    
    StackNode* getMin();
};

class SetOfStacks {
public:
    std::vector<Stack*> set;
    
    StackNode* pop();
    void push(StackNode*);
    StackNode* peek();
    bool isEmpty();
};

class Queue {
public:
    StackNode* first;
    StackNode* last;
    
    void add(StackNode*);
    StackNode* remove();
    StackNode* peek();
    bool isEmpty();
};


#endif /* stack_hpp */
