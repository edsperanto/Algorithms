// Edward Gao
// p4.cpp

// Purpose: Test if Heap class methods are correctly implemented
// Inputs: none
// Processing: Test Heap class methods
// Output: Print testing results to screen

#include <iostream>
#include "heap.h"

using namespace std;

const int RND_ARR_SIZE = 12;

int main() {

    int rndArr[RND_ARR_SIZE] = {3, 1, 0, 6, -4, 2, 1, 7, 9, 5, -3, 9};
    int tmpNum, orig, curr;

    cout << endl;
    cout << "This driver program is used to test the Heap class." << endl;
    cout << "The Heap class implemented is a min heap." << endl;
    Heap prtyQueue1;
    cout << "Priority queue 1 instantiated." << endl;
    cout << endl;

    cout << "Inserting 5 \"random\" numbers into priority queue 1..." << endl;
    for(int i = 0; i < 5; i++) {
        tmpNum = rndArr[i];
        cout << "Inserting " << tmpNum << "... ";
        prtyQueue1.insert(tmpNum);
        cout << "SUCCESS!" << endl;
    }
    cout << endl;

    cout << "Creating new priority queue 2 with priority queue 1." << endl;
    cout << "This tests the copy constructor." << endl;
    Heap prtyQueue2(prtyQueue1);
    cout << "Priority queue 2 instantiated." << endl;
    cout << endl;

    cout << "Since 5 numbers are the default size of the heap," << endl;
    cout << "all 5 numbers are expected to be successfully inserted." << endl;
    cout << endl;

    cout << "Checking that all 5 numbers are inserted" << endl;
    cout << "by removing all nodes from priority queue 1" << endl;
    cout << "and printing their current and original priorities" << endl;
    cout << "which should be equal at this point of the test." << endl;
    cout << "This process tests the isEmpty and deleteMin functions." << endl;
    cout << "They are also expected to be removed in order." << endl;
    cout << endl;

    while(!prtyQueue1.isEmpty()) {
        prtyQueue1.deleteMin(orig, curr);
        cout << "current priority: " << curr;
        cout << ", ";
        cout << "original priority: " << orig;
        cout << endl;
    }
    cout << endl;

    cout << "Assigning priority queue 2 to priority queue 1." << endl;
    cout << "Since priority queue 2 was created with priority queue 1" << endl;
    cout << "after inserting the 5 random numbers earlier," << endl;
    cout << "priority queue 1 should have the 5 random numbers again." << endl;
    cout << "This tests the overloaded assignment operator." << endl;
    prtyQueue1 = prtyQueue2;
    cout << "SUCCESS" << endl;
    cout << endl;

    cout << "Checking by removing all nodes from priority queue 1." << endl;
    while(!prtyQueue1.isEmpty()) {
        prtyQueue1.deleteMin(orig, curr);
        cout << "current priority: " << curr;
        cout << ", ";
        cout << "original priority: " << orig;
        cout << endl;
    }
    cout << endl;

    cout << "Attempting to insert 12 random numbers in priority" << endl;
    cout << "queue 1, which should force it to resize twice." << endl;
    for(int i = 0; i < RND_ARR_SIZE; i++) {
        tmpNum = rndArr[i];
        cout << "Inserting " << tmpNum << "... ";
        prtyQueue1.insert(tmpNum);
        cout << "SUCCESS!" << endl;
    }
    cout << endl;

    cout << "Reseting priority for some nodes..." << endl;
    cout << "Reseting node with original priority 9... ";
    prtyQueue1.resetPriority(9);
    cout << "SUCCESS" << endl;
    cout << "Reseting node with original priority 1... ";
    prtyQueue1.resetPriority(1);
    cout << "SUCCESS" << endl;
    cout << "Reseting node with original priority 3... ";
    prtyQueue1.resetPriority(3);
    cout << "SUCCESS" << endl;
    cout << endl;

    cout << "Checking if resetting node worked by removing" << endl;
    cout << "all nodes from priority queue 1." << endl;
    cout << "Three nodes with original priority 9, 1, and 3" << endl;
    cout << "should now have a smaller number (higher priority)." << endl;
    cout << endl;

    while(!prtyQueue1.isEmpty()) {
        prtyQueue1.deleteMin(orig, curr);
        cout << "current priority: " << curr;
        cout << ", ";
        cout << "original priority: " << orig;
        cout << endl;
    }
    cout << endl;

}
