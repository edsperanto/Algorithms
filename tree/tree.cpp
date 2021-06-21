// Edward Gao
// tree.cpp

#include "tree.h"

using namespace std;

Tree::Tree() {
    bst = nullptr;
}

Tree::Tree(const Tree& tree) {
    if(tree.bst == nullptr) {
        bst = nullptr;
    } else {
        bst = makeCopy(tree.bst);
    }
}

Tree& Tree::operator=(const Tree& tree) {
    if(this != &tree) {
        deleteAll(bst);
        bst = makeCopy(tree.bst);
    }
    return *this;
}

Tree::~Tree() {
	deleteAll(bst);
}

bool Tree::insert(int key) {
    return insert(bst, key);
}

bool Tree::findKey(int key) {
    Node* tmp = bst;
    while(tmp != nullptr && tmp->key != key) {
        if(key < tmp->key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return tmp != nullptr;
}

int Tree::findMinKey() {
    Node* tmp = bst;
    while(tmp->left != nullptr) {
        tmp = tmp->left;
    }
    return tmp->key;
}

int Tree::findMaxKey() {
    Node* tmp = bst;
    while(tmp->right != nullptr) {
        tmp = tmp->right;
    }
    return tmp->key;
}

int Tree::findHeight() {
    return findHeight(bst);
}

void Tree::preorder() {
    preorder(bst);
}

void Tree::inorder() {
	stack<Node*> stack;
	Node* current = bst;
	
	while(current != nullptr || !stack.empty()) {
		if(current != nullptr) {
			stack.push(current);
			current = current->left;
		} else {
			current = stack.top();
			stack.pop();
			cout << current->key << " ";
			current = current->right;
		}
	}
}

void Tree::remove(int key) {
    Node* parent;
    if(bst == nullptr) {
        return;
    }
    if(bst->key == key) {
        makeDeletion(bst);
    } else {
        parent = findParent(bst, key);
        if(parent != nullptr) {
            if(parent->left && parent->left->key == key) {
                makeDeletion(parent->left);
            } else {
                makeDeletion(parent->right);
            }
        }
    }
}

Tree::Node* Tree::makeCopy(Node* root) {
    if(root == nullptr) {
        return nullptr;
    } else {
        Node* tmp = new Node;
        tmp->key = root->key;
        tmp->left = makeCopy(root->left);
        tmp->right = makeCopy(root->right);
        return tmp;
    }
}

bool Tree::insert(Node*& root, int newKey) {
    if(root == nullptr) {
        root = new Node;
        root->key = newKey;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    } else if(root->key == newKey) {
        return false;
    } else if(root->key > newKey) {
        return insert(root->left, newKey);
    } else {
        return insert(root->right, newKey);
    }
}

int Tree::findHeight(Node* root) {
    if(root == nullptr) {
        return 0;
    } else {
        int lHeight = findHeight(root->left);
        int rHeight = findHeight(root->right);
        if(lHeight > rHeight) {
            return 1 + lHeight;
        } else {
            return 1 + rHeight;
        }
    }
}

void Tree::preorder(Node* root) {
    if(root != nullptr) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

Tree::Node* Tree::findParent(Node* root, int key) {
    if(key < root->key) {
        if(key == root->left->key) {
            return root;
        } else {
            return findParent(root->left, key);
        }
    } else {
        if(key == root->right->key) {
            return root;
        } else {
            return findParent(root->right, key);
        }
    }
}

void Tree::makeDeletion(Node*& node) {
    Node* tmp;
    if(node->right == nullptr) {
        tmp = node;
        node = node->left;
        delete tmp;
    } else if(node->left == nullptr) {
        tmp = node;
        node = node->right;
        delete tmp;
    } else {
        tmp = node->right;
        while(tmp->left) {
            tmp = tmp->left;
        }
        tmp->left = node->left;
        tmp = node;
        node = node->right;
        delete tmp;
    }
}

void Tree::deleteAll(Node*& root) {
    if(root != nullptr) {
        deleteAll(root->left);
        deleteAll(root->right);
        delete root;
        root = nullptr;
    }
}
