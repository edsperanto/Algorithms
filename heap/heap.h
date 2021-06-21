// Edward Gao
// heap.h

#include <iostream>

#ifndef HEAP_H
#define HEAP_H

class Heap {

    public:

        Heap();
        // default constructor
        // precondition: none
        // postcondition: root of heap instantiated with nullptr

        Heap(const Heap& heapObj);
        // copy constructor
        // precondition: argument must be of class Heap
        // postcondition: new heap created that is duplicate of argument heap

        Heap& operator=(const Heap& heapObj);
        // overloaded assignment operator
        // precondition: argument must be of class Heap
        // postcondition: old heap deleted, argument heap duplicated

        ~Heap();
        // destructor
        // precondition: none
        // postcondition: memory used by heap class freed

        bool isEmpty();
        // check if heap is empty
        // precondition: none
        // postcondition: return boolean of status of heap emptiness

        void insert(int priority);
        // insert new node into heap with given priority
        // precondition: priority is an integer
        // postcondition: new node is inserted into priority queue

        void deleteMin(int& origPrty, int& currPrty);
        // delete next item in priority queue and return values
        // precondition: priority queue is not empty
        // postcondition: next item deleted, and values returned

        void resetPriority(int priority);
        // reset node with given priority to be next item in priority queue
        // node with specified priority exists
        // next node with specified priority becomes next item in queue

    private:
    
        struct Node {
            int origPrty;
            int currPrty;
        };

        const int DEFAULT_SIZE = 5; // default size of heap
        int currSize; // current size of heap
        int maxSize; // max size of heap
        Node* heap; // heap dynamic array

        void resize();
        // resize function for heap
        // precondition: heap array is full
        // postcondition: double heap array size
        
    	void percolateDown(int hole);
    	// percolate item at hole down
    	// precondition: hole exists
    	// postcondition: node at hole percolates down until it is larger
    	//                than its parent

};

#endif

