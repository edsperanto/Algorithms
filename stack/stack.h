// Edward Gao
// stack.h

#ifndef STACK_H
#define STACK_H

const int DEFAULT_SIZE = 2;

class Stack {
    public:
        // default constructor
        Stack();
        // copy constructor
        Stack(const Stack& s);
        // overloaded assignment operator
        Stack& operator=(const Stack& s);
        // destructor
        ~Stack();
        // push new numbers to top
        bool push(int d);
        // pop number from top
        bool pop(int& d);
        // check if stack is empty
        bool empty();
    private:
        // stack dynamic array
        int* stack;
        // number of integers stored, initially there is no data
        int size;
        // total max size of array (subject to resizing)
        int totalSize;
        // resize function to increase max size to 1.5x current size
        void resize();
        // check if an integer is a prime number
        bool checkPrime(int d) const;
        // check if stack is full
        bool isFull() const;
};

#endif
