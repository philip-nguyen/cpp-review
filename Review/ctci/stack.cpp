//
//  stack.cpp
//  Review
//
//  Created by Philip Nguyen on 1/5/21.
//  Copyright © 2021 Philip Nguyen. All rights reserved.
//

#include "stack.hpp"
/******************/
// Stack functions
/******************/
StackNode* Stack::pop() {
    StackNode* temp = top;
    top = top->next;
    return temp;
}

void Stack::push(StackNode* item) {
    if(top == nullptr) {
        top = item;
        
        top->min = item;
    }
    else {
        item->next = top;
        top = item;
        if (top->min->data > item->data) {
            // make next min the old min
            top->min = item;
        }
        // set min to the already established min
        else top->min = top->next->min;
    }
    
}

StackNode* Stack::peek() {
    if(top == nullptr) return nullptr;
    return top;
}

bool Stack::isEmpty() {
    if(top == nullptr)
        return true;
    else return false;
}

StackNode* Stack::getMin() {
    return peek()->min;
}

/******************/
// Queue Functions
/******************/
void Queue::add(StackNode* item) {
    
}

// Stack and Queue Exercises
