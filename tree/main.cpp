// Edward Gao
// p3.cpp

// Purpose: Test our knowledge of binary search trees through partial
// implementation of a binary search tree class and a driver to test it.
// Inputs: No user input
// Processing: Test all functions of Tree class to make sure it works
// Output: Print testing process and results to screen

#include <string>
#include <iostream>
#include "tree.h"

using namespace std;

const int ARR_SIZE = 20;

int main() {

    bool ok;
    int rndNumArr[ARR_SIZE] = { 4, 15, 12, -9, 13, 6, -5, 11,
        1, -16, 3, -14, 18, 0, 12, -7, 13, 19, -2, 15 };

    cout << endl;
    cout << "This is the driver program used to test the Tree class." << endl;
    cout << "It will test the public functions and test edge cases." << endl;
    cout << endl;

    cout << "Instantiating new tree A... ";
    Tree treeA;
    cout << "SUCCESS" << endl;
    cout << endl;

    cout << "Inserting 20 \"random\" numbers into tree A..." << endl;
    for(int i = 0; i < ARR_SIZE; i++) {
        ok = treeA.insert(rndNumArr[i]);
        cout << "Inserting " << rndNumArr[i] << ": ";
        if(ok) {
            cout << "SUCCESS";
        } else {
            cout << "FAILED";
        }
        cout << endl;
    }
    cout << "Insert complete" << endl;
    cout << "Expected 12, 13, and 15 to fail for being duplicates." << endl;
    cout << endl;

    cout << "Instantiating new tree B by copying tree A... ";
    Tree treeB(treeA);
    cout << "SUCCESS" << endl;
    cout << "Assigning tree B to tree A... ";
    treeA = treeB;
    cout << "SUCCESS" << endl;
    cout << endl;

    cout << "Finding keys in tree A: -16, -5, 0, 4, and 9..." << endl;
    cout << "Expected smallest number (-16) to be found: ";
    cout << (treeA.findKey(-16) ? "FOUND" : "NOT FOUND") << endl;
    cout << "Expected negative number (-5) to be found: ";
    cout << (treeA.findKey(-5) ? "FOUND" : "NOT FOUND") << endl;
    cout << "Expected zero (0) to be found: ";
    cout << (treeA.findKey(0) ? "FOUND" : "NOT FOUND") << endl;
    cout << "Expected root of tree A (4) to be found: ";
    cout << (treeA.findKey(4) ? "FOUND" : "NOT FOUND") << endl;
    cout << "Expected largest number (19) to be found: ";
    cout << (treeA.findKey(19) ? "FOUND" : "NOT FOUND") << endl;
    cout << endl;

    cout << "Finding smallest key in tree A... ";
    cout << treeA.findMinKey() << endl;
    cout << "Finding largest key in tree A... ";
    cout << treeA.findMaxKey() << endl;
    cout << "Finding tree height in tree A... ";
    cout << treeA.findHeight() << endl;
    cout << endl;

    cout << "Printing tree A in order iteratively before deletions..." << endl;
    treeA.inorder();
    cout << endl;
    cout << endl;

    cout << "Deleting nodes: -16, -5, 0, 4, and 9..." << endl;
    treeA.remove(-16);
    cout << "Expected smallest number (-16) to be deleted." << endl;
    treeA.remove(-5);
    cout << "Expected negative number (-5) to be deleted." << endl;
    treeA.remove(0);
    cout << "Expected zero (0) to be deleted." << endl;
    treeA.remove(4);
    cout << "Expected root of tree A (4) to be deleted." << endl;
    treeA.remove(19);
    cout << "Expected largest number (19) to be deleted." << endl;
    cout << endl;

    cout << "Printing tree A pre-order recursively after deletions..." << endl;
    treeA.preorder();
    cout << endl;
    cout << endl;

}
