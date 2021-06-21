// Edward Gao
// heap.cpp

#include "heap.h"

using namespace std;

Heap::Heap() {
    maxSize = DEFAULT_SIZE;
    heap = new Node[maxSize+1];
    currSize = 0;
}

Heap::Heap(const Heap& heapObj) {
    if(heapObj.heap == nullptr) {
        heap = nullptr;
    } else {
        maxSize = heapObj.maxSize;
        currSize = heapObj.currSize;
        heap = new Node[maxSize+1];
        for(int i = 1; i <= currSize; i++) {
            heap[i].currPrty = heapObj.heap[i].currPrty;
            heap[i].origPrty = heapObj.heap[i].origPrty;
        }
    }
}

Heap& Heap::operator=(const Heap& heapObj) {
    if(this != &heapObj) {
        delete [] heap;
        maxSize = heapObj.maxSize;
        currSize = heapObj.currSize;
        heap = new Node[maxSize+1];
        for(int i = 1; i <= currSize; i++) {
            heap[i].currPrty = heapObj.heap[i].currPrty;
            heap[i].origPrty = heapObj.heap[i].origPrty;
        }
    }
    return *this;
}

Heap::~Heap() {
    delete [] heap;
}

bool Heap::isEmpty() {
    return currSize == 0;
}

void Heap::insert(int priority) {
    if(currSize == maxSize) {
        resize();
    }
	int hole = ++currSize;
	while(hole > 1 && priority < heap[hole/2].currPrty) {
		heap[hole] = heap[hole/2];
		hole = hole / 2;
	}
	heap[hole].currPrty = priority;
    heap[hole].origPrty = priority;
}

void Heap::deleteMin(int& origPrty, int& currPrty) {
    origPrty = heap[1].origPrty;
    currPrty = heap[1].currPrty;
    heap[1] = heap[currSize--];
    percolateDown(1);
}

void Heap::resetPriority(int priority) {
    // find index of node to be resetted
    int idx = 1;
    while(idx <= maxSize && heap[idx].origPrty != priority) {
        idx++;
    }
    if(idx <= maxSize) {
        // temporarily storing next item in priority queue
        Node tmpNode;
        tmpNode.currPrty = heap[1].currPrty;
        tmpNode.origPrty = heap[1].origPrty;
        // replace next item with item to be reset
        heap[1].currPrty -= 1;
        heap[1].origPrty = heap[idx].origPrty;
        // percolate hole (idx) up to put tmp Node in the right place
        while(idx > 1 && tmpNode.currPrty < heap[idx/2].currPrty) {
            heap[idx] = heap[idx/2];
            idx = idx / 2;
        }
        heap[idx].currPrty = tmpNode.currPrty;
        heap[idx].origPrty = tmpNode.origPrty;
    }
}

void Heap::resize() {
    maxSize *= 2;
    Node* tmpArr = new Node[maxSize+1];
    for(int i = 1; i <= currSize; i++) {
        tmpArr[i].currPrty = heap[i].currPrty;
        tmpArr[i].origPrty = heap[i].origPrty;
    }
    delete [] heap;
    heap = tmpArr;
}

void Heap::percolateDown(int hole) {
    Node tmp = heap[hole];
    // while child nodes are smaller than current node
    // and children are within current max size of heap
    while((hole*2 <= currSize && tmp.currPrty > heap[hole*2].currPrty) ||
        (hole*2+1 <= currSize && tmp.currPrty > heap[hole*2+1].currPrty)) {
        // if right child node is smaller than left child node
        // and right child is within current max size of heap
        if(hole*2+1 <= currSize && 
            heap[hole*2+1].currPrty < heap[hole*2].currPrty) {
            heap[hole] = heap[hole*2+1];
            hole = hole*2+1;
        // if left child node is smaller than right child node
        } else {
            heap[hole] = heap[hole*2];
            hole = hole*2;
        }
    }
    heap[hole] = tmp;
}
