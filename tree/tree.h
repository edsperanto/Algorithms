// Edward Gao
// tree.h

#include <iostream>
#include <stack>

#ifndef TREE_H
#define TREE_H

class Tree {

    public:

        Tree();
        // default constructor
        // precondition: none
        // postcondition: root of bst instantiated with nullptr

        Tree(const Tree& tree);
        // copy constructor
        // precondition: argument must be of class Tree
        // postcondition: new bst created that is duplicate of argument tree

        Tree& operator=(const Tree& tree);
        // overloaded assignment operator
        // precondition: argument must be of class Tree
        // postcondition: old bst deleted, argument tree duplicated

        ~Tree();
        // destructor
        // precondition: none
        // postcondition: memory used by tree class freed

        bool insert(int key);
        // public insertion function (calls private insert)
        // precondition: argument key must be integer
        // postcondition: key inserted into bst in correct order
        
        bool findKey(int key);
        // public find key function
        // precondition: argument key must be integer
        // postcondition: return true or false of whether key is found

        int findMinKey();
        // find smallest key in tree
        // precondition: tree must not be empty
        // postcondition: return value of smallest key

        int findMaxKey();
        // find largest key in tree
        // precondition: tree must not be empty
        // postcondition: return value of largest key
        
        int findHeight();
        // public find height function (calls private findHeight)
        // precondition: none
        // postcondition: return height of tree

        void preorder();
        // public pre-order traversal (calls private preorder)
        // precondition: none
        // postcondition: print tree content preorder

        void inorder();
        // in-order traversal (iterative)
        // precondition: none
        // postcondition: print tree content postorder

        void remove(int key);
        // public remove key function
        // (calls private findParent and makeDeletion function)
        // precondition: argument key must be integer
        // postcondition: specified key is removed from tree

    private:
    
	    struct Node {
		    int key;
		    Node* left;
		    Node* right;
		};
		// Node struct with key, pointer to left, and pointer to right

        Node* bst;
        // binary search tree
        
        Node* makeCopy(Node* root);
        // private make copy function (recursive)
        // precondition: argument root must be Node
        // postcondition: return recursive deep copy of node and subnodes

        bool insert(Node*& root, int key);
        // private insertion function (recursive)
        // precondition: argument root must be Node, key must be integer
        // postcondition: key inserted into bst in correct order

        int findHeight(Node* root);
        // private find height function (recursive)
        // precondition: argument root must be Node
        // postcondition: return height of tree
        
        void preorder(Node* root);
        // private pre-order traversal (recursive)
        // precondition: argument root must be Node
        // postcondition: print tree content preorder
        
        Node* findParent(Node* root, int key);
        // private find parent function (recursive)
        // precondition: argument root must be Node, key must be integer
        // postcondition: parent node of node with key is returned

        void makeDeletion(Node*& node);
        // private make deletion function
        // precondition: argument node must be Node
        // postcondition: node is removed from tree, and tree re-ordered
        
        void deleteAll(Node*& root);
        // private delete all function (recursive)
        // precondition: none
        // postcondition: memory used by tree class freed

};

#endif
