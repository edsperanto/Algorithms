// Edward Gao
// p1.cpp

#include <string>
#include <iostream>
#include "stack.h"

using namespace std;

void pushNext(Stack& s, int d);
void popNext(Stack& s);

int main() {

    cout << endl;
    cout << "This is the driver program used to test the Stack class." << endl;
    cout << "It will test the public functions and test edge cases." << endl;

    Stack s1;
    cout << endl;
    cout << "Initially empty: ";
    if(s1.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    cout << endl;
    cout << "Pushing integers in order: 25, 11, 7, 13, 2, 125" << endl;
    pushNext(s1, 25);
    pushNext(s1, 11);
    pushNext(s1, 7);
    pushNext(s1, 13);
    pushNext(s1, 2);
    pushNext(s1, 125);

    cout << endl;
    cout << "Should only successfully pop primes: 2, 13, 7, 11" << endl;
    cout << "Which also confirms resize is working properly" << endl;
    cout << "Because the default stack size starts at 2" << endl;
    cout << "Which is not enough room for 4 integers, unless resized" << endl;
    popNext(s1);
    popNext(s1);
    popNext(s1);
    popNext(s1);
    popNext(s1);
    popNext(s1);

    cout << endl;
    cout << "Pushing integers in order: 53, 19, 20, 0, 1, -3" << endl;
    pushNext(s1, 53);
    pushNext(s1, 19);
    pushNext(s1, 20);
    pushNext(s1, 0);
    pushNext(s1, 1);
    pushNext(s1, -3);

    cout << endl;
    cout << "Should only successfully pop primes: 19, 53" << endl;
    popNext(s1);
    popNext(s1);
    popNext(s1);
    popNext(s1);
    popNext(s1);
    popNext(s1);

    cout << endl;
    cout << "Creating new stack and pushing 3, 5, 7...";
    Stack s2;
    pushNext(s2, 3);
    pushNext(s2, 5);
    pushNext(s2, 7);

    cout << endl;
    cout << "Testing copy constructor, copy stack should pop 7, 5, 3." << endl;
    Stack s3(s2);
    popNext(s3);
    popNext(s3);
    popNext(s3);

    cout << endl;
    cout << "Testing overloaded assignment operator..." << endl;
    cout << "Expecting assigned stack to pop 7, 5, 3." << endl;
    s3 = s2;
    popNext(s3);
    popNext(s3);
    popNext(s3);

    cout << endl;
    return 0;

}

void pushNext(Stack& s, int d) {
    bool success = s.push(d);
    if(success) {
        cout << "Pushed number: " << d << endl;
    } else {
        cout << "Not a prime, " << d << " rejected" << endl;
    }
}

void popNext(Stack& s) {
    int num;
    bool success = s.pop(num);
    if(success) {
        cout << "Popped number: " << num << endl;
    } else {
        cout << "Cannot pop empty stack" << endl;
    }
}
