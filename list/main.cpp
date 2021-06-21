// Edward Gao
// p6.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iterator>

using namespace std;

const int INIT_SIZE = 1000;
const int MAX_INT = 100;
const int COL_SIZE = 5;
const int NUMS_PER_ROW = 10;

bool isPrime(int num);
// checks if number is prime
// precondition: argument is an int
// postcondition: returns whether integer is prime

void printList(list<int> intList);
// prints all elements in STL list
// precondition: argument is an STL list
// postcondition: STL list is printed

int main() {

    bool incomplete = true;
    bool leftParity, rightParity;
    int intArr[INIT_SIZE];
    list<int> intList;
    list<int>::iterator it;
    ostream_iterator<int> screen(cout, " ");
    srand(time(0));

    cout << "========== GENERATING RANDOM NUMBERS ==========" << endl;
    for(int i = 0; i < INIT_SIZE; i++) {
        intArr[i] = rand() % MAX_INT;
    }
    cout << "SUCCESS!" << endl;
    cout << endl;

    cout << "========== STORING INTEGERS IN LIST CONTAINER ==========" << endl;
    intList.assign(intArr, intArr + INIT_SIZE);
    cout << "SUCCESS!" << endl;
    cout << "I stored my numbers in a list because" << endl;
    cout << "this assignment involves a lot of deletion" << endl;
    cout << "and deletion has O(1) time in a STL list." << endl;
    cout << endl;

    cout << "========== PRINTING LIST ==========" << endl;
    cout << "This list has " << intList.size() << " items." << endl;
    printList(intList);
    cout << endl;

    cout << "========== REMOVING MULTIPLES OF 5 ==========" << endl;
    for(it = intList.begin(); it != intList.end();) {
        if(*it % 5 == 0 && *it != 0) {
            it = intList.erase(it);
        } else {
            ++it;
        }
    }
    cout << "SUCCESS!" << endl;
    cout << endl;

    cout << "========== PRINTING REMAINING LIST ==========" << endl;
    cout << "This list has " << intList.size() << " items left." << endl;
    printList(intList);
    cout << endl;

    while(incomplete) {

        incomplete = false;

        cout << "===== REMOVING ALL PRIMES BETWEEN MIXED PARITY =====" << endl;
        for(it = next(intList.begin()); it != prev(intList.end());) {
            leftParity = *prev(it) % 2;
            rightParity = *next(it) % 2;
            if((leftParity != rightParity) && isPrime(*it)) {
                it = intList.erase(it);
                incomplete = true;
            } else {
                ++it;
            }
        }
        cout << "SUCCESS" << endl;
        cout << endl;

        cout << "========== PRINTING REMAINING LIST ==========" << endl;
        cout << "This list has " << intList.size() << " items left." << endl;
        printList(intList);
        cout << endl << endl;

    }

    cout << "========== FINISHED ==========" << endl;
    cout << "List size unchanged from previous run." << endl;
    cout << "All primes between two integers of mixed parity removed!";
    cout << endl << endl;

}

bool isPrime(int num) {
    int testNum = 3;
    if(num < testNum) {
        return true;
    } else if(num % 2 == 0) {
        return false;
    } else {
        while(testNum < num/2) {
            if(num % testNum == 0) {
                return false;
            }
            testNum += 2;
        }
    }
    return true;
}

void printList(list<int> intList) {
    int itemsInRow = 0;
    list<int>::iterator it;
    for(it = intList.begin(); it != intList.end(); ++it) {
        cout << setw(COL_SIZE);
        cout << *it;
        if(itemsInRow++ % NUMS_PER_ROW == NUMS_PER_ROW - 1) {
            cout << endl;
        }
    }
}
