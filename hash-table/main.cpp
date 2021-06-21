// Edward Gao
// p5.cpp

// Purpose: Use hash table to tally words in text
// Inputs: 41.txt, user query
// Processing: Tally count for each word in text using a hash table
// Output: Hash table info, and query results

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int HASH_TABLE_SIZE = 6007;
const string FILENAME = "41.txt";

struct Node {
    string word;
    int count;
    Node* next;
};

bool isAlpha(char letter);
// checks if letter is in the English alphabet
// precondition: letter exists
// postcondition: boolean of whether letter is in alphabet

string cleanUp(string word);
// cleans up words to only contain alphabets, -, :, /, .
// precondition: word exists
// postcondition: word cleaned up

int hashWord(string word, int tableSize);
// hashes word into number of size 0 to tableSize-1
// precondition: word exists, tableSize > 0
// postcondition: hash returned

void insert(Node* hashTable[], string word, int& nCol, int& uniqWrds);
// inserts word into hash table
// precondition: hash table and word exists
// postcondition: word inserted into hash table

void find(string word, Node* hashTable[], int& searchCount);
// finds word in hash table
// precondition: word and hash table exists
// postcondition: return word count in hash table

void capitalize(string& word);
// capitalize all letters in string
// precondition: word exists
// postcondition: word capitalized

void deleteEntire(Node* hashTable[]);
// deallocate all memory used by hash table
// precondition: hash table exists
// postcondition: hash table memory deallocated

int main() {

    int numCollisions = 0;
    int numUniqWords = 0;
    int totalWords = 0;
    float loadFactor;
    bool searching = true;
    int searchCount;
    char resume = 'a';

    string word;
    Node* hashTable[HASH_TABLE_SIZE];
    
    for(int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }

    cout << endl;
    cout << "Reading file 41.txt..." << endl;
    ifstream inFile;
    inFile.open(FILENAME);
    if(inFile.fail()) {
        cout << "Read file 41.txt failed" << endl;
    }

    while(inFile >> word) {
        word = cleanUp(word);
        if(word.length() > 4) {
            totalWords++;
            insert(hashTable, word, numCollisions, numUniqWords);
        }
    }
    inFile.close();
    cout << "Finished inserting words in hash table..." << endl;
    cout << endl;

    cout << "==========RESULTS==========" << endl;
    loadFactor = (float)numUniqWords / HASH_TABLE_SIZE;
    cout << "Load factor: " << loadFactor << endl;
    cout << "# of collisions: " << numCollisions << endl;
    cout << "# of unique words: " << numUniqWords << endl;
    cout << "total # of words: " << totalWords << endl;
    cout << endl;

    cout << "========SEARCH WORD========" << endl;
    while(searching) {
        cout << "Query: ";
        cin >> word;
        find(word, hashTable, searchCount);
        cout << "The word " << word << " appeared ";
        cout << searchCount << " time(s)." << endl;
        while(!(resume == 'y' || resume == 'n')) {
            cout << "Would you like to continue? (y/n) ";
            cin >> resume;
        }
        if(resume == 'n') searching = false;
        resume = 'a';
    }
    cout << endl;

    cout << "Deallocating memory for hash table" << endl;
    deleteEntire(hashTable);
    cout << "Deallocation complete" << endl;
    cout << endl;

}

bool isAlpha(char letter) {
    bool isCapital = letter >= 'A' && letter <= 'Z';
    bool isLower = letter >= 'a' && letter <= 'z';
    return isCapital || isLower;
}

string cleanUp(string word) {
    string newWord = "";
    int rightBound = word.length() - 1;
    int left = 0;
    int right = rightBound;
    while(!isAlpha(word[left]) && left < rightBound) left++;
    while(!isAlpha(word[right]) && right > left) right--;
    for(int i = left; i <= right; i++) {
        newWord += word[i];
    }
    capitalize(newWord);
    return newWord;
}

int hashWord(string word, int tableSize) {
    unsigned long hashVal = 5381;
    int c;
    for(unsigned i = 0; i < word.length(); i++) {
        c = word[i];
        hashVal = hashVal * 33 + c;
    }
    return hashVal % tableSize;
}

void insert(Node* hashTable[], string word, int& nCol, int& uniqWrds) {
    int loc;
    int tmpCollisions = 0;
    Node* newNode;
    Node* curr;
    capitalize(word);
    loc = hashWord(word, HASH_TABLE_SIZE);
    // no collisions
    if(hashTable[loc] == nullptr) {
        newNode = new Node;
        newNode->word = word;
        newNode->count = 1;
        newNode->next = nullptr;
        hashTable[loc] = newNode;
        uniqWrds++;
    // maybe collision
    } else {
        tmpCollisions++;
        curr = hashTable[loc];
        while(curr->next != nullptr && curr->word != word) {
            curr = curr->next;
            tmpCollisions++;
        }
        // yes, collision
        if(curr->next == nullptr) {
            newNode = new Node;
            newNode->word = word;
            newNode->count = 1;
            newNode->next = nullptr;
            curr->next = newNode;
            nCol += tmpCollisions;
            uniqWrds++;
        // no, already exists
        } else if(curr->word == word) {
            curr->count = curr->count + 1;
        }
    }
}

void find(string word, Node* hashTable[], int& searchCount) {
    int loc;
    Node* curr;
    searchCount = 0;
    capitalize(word);
    loc = hashWord(word, HASH_TABLE_SIZE);
    curr = hashTable[loc];
    if(curr != nullptr) {
        while(curr != nullptr && curr->word != word) {
            curr = curr->next;
        }
        if(curr != nullptr) {
            searchCount = curr->count;
        }
    }
}

void capitalize(string& word) {
    char letter;
    string newWord = "";
    for(unsigned i = 0; i < word.length(); i++) {
        letter = word[i];
        if(letter >= 'a' && letter <= 'z') {
            newWord += letter - ('a' - 'A');
        } else {
            newWord += letter;
        }
    }
    word = newWord;
}

void deleteEntire(Node* hashTable[]) {
    Node* tmp;
    Node* del;
    for(int i = 0; i < HASH_TABLE_SIZE; i++) {
        tmp = hashTable[i];
        while(tmp != nullptr) {
            del = tmp;
            tmp = tmp->next;
            delete del;
        }
    }
}
