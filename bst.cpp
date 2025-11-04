//====================================================
// bst.cpp
//
// Created by Gabe, Ramatu, and Phlynn
//====================================================
#ifndef BST_CPP
#define BST_CPP

#include "iostream"
#include "queue"
#include "string"
#include "sstream"
using namespace std;
#include "bst.h"


//====================================================
// BST FUNCTIONS
//====================================================

template <class D, class K>
BST<D, K>::BST() {
    root=nullptr;
}


template <class D, class K>
BST<D, K>::~BST() {
    clear(root);
}

template <class D, class K>
void BST<D, K>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
//==========================================================
// empty
// checks if the bst is empty.
// parameters: none
// pre-condition: a valid created bst.
// post-condition: a bool depicting whether the bst is empty
//==========================================================
template <class D, class K>
bool BST<D, K>::empty() {
    return root == nullptr;
}

//==========================================================
// insert
// inserts key k into a valid bst
// parameters: T& d - element's template data
//             const long& k - numeric key value
// pre-condition: a valid created bst
// post-condition: bst with added node with data d and key k
//==========================================================
template <class D, class K>
void BST<D, K>::insert( const D& d, const K&  k ) {
    Node* z = new Node(d, k);
    Node* x = root;
    Node* y = nullptr;
    {
        while(x != nullptr){
            y=x;
            if (z->key < x->key){
                x = x->left;
            }
            else{
                x =x->right;
            }
        }
        z->parent = y;
        if(y==nullptr){
            root = z;
            return;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else{
            y->right = z;
        }

    }
}

//==========================================================
// get
// returns key from node with the correct associated data
// parameters: const long& k - numeric key value
// pre-condition: an exisitng bst
// post-condition: returned key k and data d from node if it exists
//==========================================================
template <class D, class K>
D BST<D, K>::get( const K&  k ) {
    Node* current = root;
    while (current != nullptr) {
        if (k == current->key) {
            return current->data;
        } else if (k < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // If key not found, return default
    return D();

}

//==========================================================
// remove 
// deletes the first node it finds with key k (closest to root)
// parameters: long k - numeric key value
// pre-condition: non-empty bst that maintains bst property
// post-condition: bst's size reduced by one with first node of key k
//                 removed
//==========================================================
template <class D, class K>
void BST<D, K>::remove(K k) {
    Node* curr = root;
    
    // Find the node to delete
    while (curr != nullptr && curr->key != k) {
        if (k < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    
    // If key not found, return
    if (curr == nullptr) return;
    
    // Case 1: Node has no left child
    if (curr->left == nullptr) {
        transplant(curr, curr->right);
    }
    // Case 2: Node has no right child
    else if (curr->right == nullptr) {
        transplant(curr, curr->left);
    }
    // Case 3: Node has both children
    else {
        // Find minimum node in right subtree (successor)
        Node* succ = curr->right;
        while (succ->left != nullptr) {
            succ = succ->left;
        }
        
        // If successor is not the direct right child
        if (succ->parent != curr) {
            transplant(succ, succ->right);
            succ->right = curr->right;
            succ->right->parent = succ;
        }
        
        transplant(curr, succ);
        succ->left = curr->left;
        succ->left->parent = succ;
    }
    
    delete curr;
}

//==========================================================
// transplant 
// replaces one subtree as a child of it parent with another subtree
// parameters: Node *x - pointer to node of subtree to be replaced 
//             Node *y - pointer to node of subtree replacing subtree rooted at x
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
void BST<D, K>::transplant(Node *x, Node *y) {
    if (x->parent == nullptr) 
        root = y;

    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else
        x->parent->right = y;
    
    if (y != nullptr)
        y->parent = x->parent;
}


//==========================================================
// max_data
// max data retrieved from associated maximum key k
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
D BST<D, K>::max_data( void ) {  // Change return type from K to D
    Node* curr = root;
    while (curr->right != nullptr)
        curr = curr->right;
    return curr->data;  // Return data, not key
}

//==========================================================
// max_key
// returns associated maximum key k
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
K BST<D, K>::max_key( void ) {  // Change return type from D to K
    Node* curr = root;
    while (curr->right != nullptr)
        curr = curr->right;
    return curr->key;
}


//==========================================================
// min_data
// returns associated minimum data d when retrieving the minimum key k
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
D BST<D, K>::min_data( void ) {  // Change return type from K to D
    Node* curr = root;
    while (curr->left != nullptr)
        curr = curr->left;
    return curr->data;  // Return data, not key
}


//==========================================================
// min_key
// returns minimum key k 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
K BST<D, K>::min_key( void ) {
    Node* curr = root;

    while (curr->left != nullptr)
        curr = curr->left;

    return curr->key;
}
// ==========================================================
// successor

// parameters: K k - numeric key value
// pre-condition: 
// post-condition: 
// ==========================================================
template <class D, class K>
K BST<D, K>::successor( K k ) {
    Node* current = root;
    Node* succ = nullptr;

    // Step 1: find the node with key k
    while (current) {
        if (k < current->key) {
            succ = current;      // potential successor
            current = current->left;
        } else if (k > current->key) {
            current = current->right;
        } else {
            // Node found
            if (current->right) {
                current = current->right;
                while (current->left) current = current->left;
                return current->key;
            } else {
                // Successor is ancestor
                return succ ? succ->key : K(); // return default if no successor
            }
        }
    }

    // If key not found, return default
    return K();
}

//==========================================================
// in_order
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
string BST<D, K>::in_order() {
    ostringstream oss;
    in_order_helper(root, oss);
    string result = oss.str();
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();  // Remove trailing space
    }
    return result;
}


template <class D, class K>
void BST<D, K>::in_order_helper(Node* node, ostringstream& oss) {
    if (node == nullptr) return;
    
    in_order_helper(node->left, oss);
    oss << node->key << " ";  // Always add space after key
    in_order_helper(node->right, oss);
}



//==========================================================
// trim
// modifies bst so all remaining keys are within the interval
// [low, high] and retains bst's structure
// parameters:  K low - numeric lower bound for modified bst
//              K high - numeric upper bound for modified bst
// pre-condition: valid existing bst
// post-condition: modified bst with keys in the range of [low, high]
//==========================================================
template <class D, class K>
void BST<D, K>::trim(K low, K high) {
    root = trim_helper(root, low, high);
}

template <class D, class K>
typename BST<D, K>::Node* BST<D, K>::trim_helper(Node* node, K low, K high) {
    if (node == nullptr) return nullptr;
    
    // If key is less than low, trim left subtree and return right
    if (node->key < low) {
        Node* right = trim_helper(node->right, low, high);
        delete node;
        return right;
    }
    
    // If key is greater than high, trim right subtree and return left
    if (node->key > high) {
        Node* left = trim_helper(node->left, low, high);
        delete node;
        return left;
    }
    
    // Key is in range, recursively trim both subtrees
    node->left = trim_helper(node->left, low, high);
    node->right = trim_helper(node->right, low, high);
    
    // Update parent pointers
    if (node->left) node->left->parent = node;
    if (node->right) node->right->parent = node;
    
    return node;
}

//==========================================================
// to_string
// 
// parameters: none
// pre-condition: valid existing bst
// post-condition: string of bst 
//==========================================================
template <class D, class K>
string BST<D, K>::to_string( void ) {
 if (root == nullptr) 
        return "";
    ostringstream oss;
    queue<Node*> q;
    q.push(root);
    bool first = true;
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (!first) oss << " ";
        oss << current->key;
        first = false;
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    
    return oss.str();

}

// template class BST<string, int>;
// template class BST<string, string>;
#endif