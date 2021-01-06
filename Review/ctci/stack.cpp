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
    if (top->data == min->data)
        min = min->next;
    return temp;
}

void Stack::push(StackNode* item) {
    if(top == nullptr) {
        top = item;
        
        min = new StackNode(item->data);
    }
    else {
        item->next = top;
        top = item;
        if (min->data > item->data) {
            // make next min the old min
            min->next = new StackNode(min->data);
            // the min now points to item
            min->data = item->data;
        }
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
    return min;
}

/******************/
// Queue Functions
/******************/
void Queue::add(StackNode* item) {
    
}

// Stack and Queue Exercises
