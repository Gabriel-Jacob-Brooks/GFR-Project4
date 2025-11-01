//====================================================
// bst.cpp
//
// Created by Gabe, Ramatu, and Phlynn
//====================================================

#include "iostream"
#include "bst.h"
#include "string"
#include "sstream"
using namespace std;

#ifndef BST_CPP
#define BST_CPP


//====================================================
// BST FUNCTIONS
//====================================================

template <class T>
bst<T>::bst() {
    root=nullptr;

}


template <class T>
bst<T>::~bst( void ) {
 
}
//==========================================================
// empty
// checks if the bst is empty.
// parameters: none
// pre-condition: a valid created bst.
// post-condition: a bool depicting whether the bst is empty
//==========================================================
template <class T>
bool bst<T>::empty( void ) {


}

//==========================================================
// insert
// inserts key k into a valid bst
// parameters: T& d - element's template data
//             const long& k - numeric key value
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
void bst<T>::insert( const T& d, const long&  k ) {
    Node<T>* x = new Node<T>;
  
}

//==========================================================
// get
// returns key from node with the correct associated data
// parameters: const long& k - numeric key value
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::get( const long&  k ) {
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
    return T(); 

}

//==========================================================
// remove 
// deletes the first node it finds with key k (closest to root)
// parameters: long k - numeric key value
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
void bst<T>::remove( long k ) {

    Node* curr = root;

    while (curr != nullptr) { // finding key in tree
        if (k == curr->key)
            delete curr->key;
        else if (k < curr->key)
            curr = curr -> left;
        else
            curr = curr -> right;
        }
        // delete key in tree
        if (curr -> left == nullptr)
            transplant(curr, curr -> right);
        else if (curr -> right == nullptr)
            transplant(curr, curr -> left);
    return;
}

//==========================================================
// max_data
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::max_data( void ) {
    Node* max = root.max_key(); // retreive key not data fix 
    return max;
}

//==========================================================
// max_key
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::max_key( void ) {

    Node* curr = root;

    while (curr -> right != nullptr)
        curr = curr -> right;

    return curr -> key;
}

//==========================================================
// min_data
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::min_data( void ) {

    Node* min = root.min_key(); // retreives key not data fix
    return min;
}

//==========================================================
// min_key
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::min_key( void ) {
    Node* curr = root;

    while (curr -> left != nullptr)
        curr = curr -> left;

    return curr -> key;

}

//==========================================================
// successor
// 
// parameters: long k - numeric key value
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::successor( long k ) {


}

//==========================================================
// in_order
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
long bst<T>::in_order( void ) {
    ostringstream oss;
    in_order_helper(root, oss);
    return oss.str();

}

// Add helper function
template <class T>
void bst<T>::in_order_helper(Node* node, ostringstream& oss) {
    static bool first = true;
    if (node == nullptr) return;
    
    in_order_helper(node->left, oss);    // Left subtree
    if (!first) oss << " ";
    oss << node->key;                    // Current node
    first = false;
    in_order_helper(node->right, oss);   // Right subtree
}

template <class T>
void bst<T>::transplant( const long& x, const long& y) {
    if (x->parent == nullptr) // end to check logic
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else (x->parent->right = y)
    if ( y == nullptr )
        y->parent = x->parent;

}
//==========================================================
// trim
// 
// parameters:  long low - 
//              long high - 
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
void bst<T>::trim( long low, long high ) {

  
}

//==========================================================
// to_string
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class T>
string bst<T>::to_string( void ) {
    if (root == nullptr) 
        return "";
    ostringstream oss;
    queue<Node*> q;
    q.push(root);
    bool first = true;
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left) q.push(current->left);
        if (!first) oss << " ";
        oss << current->key;
        first = false;
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    
    return oss.str();

}

#endif