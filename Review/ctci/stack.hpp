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
    
    Stack(StackNode* n) { top = n; }
    
    StackNode* pop();
    void push(StackNode*);
    StackNode* peek();
    bool isEmpty();
    
    StackNode* getMin();
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
