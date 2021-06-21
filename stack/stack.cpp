// Edward Gao
// stack.cpp

#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
    size = 0;
    totalSize = DEFAULT_SIZE;
    stack = new int[totalSize];
}

Stack::Stack(const Stack& s) {
    size = s.size;
    totalSize = s.totalSize;
    stack = new int[totalSize];
    // no need to worry about prime when copying
    for(int i = 0; i < size; i++) {
        stack[i] = s.stack[i];
    }
}

Stack& Stack::operator=(const Stack& s) {
    if(this == &s) {
        return *this;
    } else {
        delete [] stack;
        size = s.size;
        totalSize = s.totalSize;
        stack = new int[totalSize];
        // no need to worry about prime when copying
        for(int i = 0; i < size; i++) {
            stack[i] = s.stack[i];
        }
        return *this;
    }
}

Stack::~Stack() {
    delete [] stack;
}

bool Stack::push(int d) {
    bool isPrime = checkPrime(d);
    if(isPrime) {
        if(isFull()) resize();
        stack[size++] = d;
    }
    return isPrime;
}

bool Stack::pop(int& d) {
    bool notEmpty = size > 0;
    if(notEmpty) {
        d = stack[--size];
    }
    return notEmpty;
}

bool Stack::empty() {
    return size == 0;
}

void Stack::resize() {
    totalSize = static_cast<int>(totalSize * 1.5);
    int* newStack = new int[totalSize];
    for(int i = 0; i < size; i++) {
        newStack[i] = stack[i];
    }
    delete [] stack;
    stack = newStack;
}

bool Stack::checkPrime(int d) const {
    bool prime = true; // assume is prime until proven otherwise
    const int min = 3; // min number used to test if prime
    const int max = d/2; // max number used to test if prime
    if(d < 2) return false;
    if(d % 2 == 0 && d != 2) return false;
    for(int test = min; test < max; test+=2) { 
        if(d % test == 0) {
            prime = false;
            test = max;
        }
    }
    return prime;
}

bool Stack::isFull() const {
    return size == totalSize;
}
