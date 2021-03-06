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
    size--;
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
    size++;
    
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
// SetOfStacks Functions
/******************/
void SetOfStacks::push(StackNode* n) {
    // if the set is empty OR current stack is maxed...
    if(set.empty() || set.back()->size == 10) {
        // start a new stack
        Stack* s = new Stack(n);
        // add the stack to the set of stacks
        set.push_back(s);
    }
    else {
        // add node to the most current stack
        set.back()->push(n);
    }
}

StackNode* SetOfStacks::pop() {
    // if the current stack is not empty
    // pop from the current stack
    // otherwise
    if(set.empty() || set.back()->isEmpty())
       return nullptr;
    else {
        set.back()->size--;
        // if the set is popped back
        if(set.back()->size <= 0) set.pop_back();
        return set.back()->pop();
    }
}

StackNode* SetOfStacks::peek() {
    if(set.empty() && set.back()->isEmpty()) {
        return nullptr;
    }
    else
        return set.back()->pop();
}

/******************/
// Queue Functions
/******************/
void Queue::add(StackNode* item) {
    if (item != nullptr) {
        last->next = item;
        last = last->next;
    }
    else { // it's an empty queue
        first = item;
        last = item;
    }
}

StackNode* Queue::remove() {
    if(first != nullptr) {
        StackNode* ret = first;
        first = first->next;
        return ret;
    }
    else return nullptr;
}

StackNode* Queue::peek() {
    if(first != nullptr) {
        return first;
    }
    else return nullptr;
}

bool Queue::isEmpty() {
    if(first != nullptr)
        return false;
    else return true;
}

// Stack and Queue Exercises
