// Edward Gao
// p2.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

struct Node {
	int data;
	Node* next;
};

const int LL_SIZE = 50;
const int MAX_NUM = 1000;
const string OUT_A = "P2OutputA.txt";
const string OUT_B = "P2OutputB.txt";

void insertList(Node* &h, int d);
void deleteList(Node* &h, int d);
void printList(Node* h, ostream& f);
void freeMemory(Node* &h);

int main() {
	
	srand(time(0));
	int largest, smallest, middle;
	Node* head = nullptr;
	
	// a. construct a linked list of at least size 50
	for(int i = 0; i < LL_SIZE; i++) {
		int num = rand() % MAX_NUM;
		insertList(head, num);
		if(i == 0) largest = smallest = middle = num;
		if(num > largest) largest = num;
		if(num < smallest) smallest = num;
		if(middle == largest || middle == smallest) {
			if(num != largest && num != smallest) {
				middle = num;
			}
		}
	}
	cout << "Created linked list of size " << LL_SIZE;
	cout << endl;
	
	// b. store new linked list  in P2OutputA.txt
	ofstream outfile;
	outfile.open(OUT_A);
	printList(head, outfile);
	outfile.close();
	cout << "Stored linked list in output file: ";
	cout << OUT_A << endl;
	
	// c. delete the smallest element
	deleteList(head, smallest);
	cout << "Smallest deleted: " << smallest << endl;
	
	// d. delete the largest element
	deleteList(head, largest);
	cout << "Largest deleted: " << largest << endl;
	
	// e. delete a middle element
	deleteList(head, middle);
	cout << "Middle deleted: " << middle << endl;
	
	// f. store updated linked list in P2OutputB.txt
	outfile.open(OUT_B);
	printList(head, outfile);
	outfile.close();
	cout << "Stored linked list in output file: ";
	cout << OUT_B << endl;
	
	freeMemory(head);
	
}

void insertList(Node* &h, int d) {
	Node* tmp = h;
	Node* newNode = new Node;
	newNode->data = d;
	if(h == nullptr || tmp->data > d) {
		newNode->next = tmp;
		h = newNode;
	} else {
		while(tmp->next != nullptr && tmp->next->data < d) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}

void deleteList(Node* &h, int d) {
	Node* prev;
	Node* curr = h;
	if(h != nullptr) {
		while(curr != nullptr && curr->data < d) {
			prev = curr;
			curr = curr->next;
		}
		if(h->data == d) {
			h = curr->next;
			delete curr;
		} else if (curr != nullptr && curr->data == d) {
			prev->next = curr->next;
			delete curr;
		}
	}
}

void printList(Node* h, ostream& f) {
	Node* tmp = h;
	int count = 0;
	const int COL = 5;
	const int NUM_COLS = 7;
	while(tmp != nullptr) {
		f << setw(COL) << tmp->data;
		tmp = tmp->next;
		count++;
		if(count % NUM_COLS == 0) {
			f << endl;
		}
	}
	f << endl;
}

void freeMemory(Node* &h) {
	Node* del;
	while(h != nullptr) {
		del = h;
		h = h->next;
		delete del;
	}
}
