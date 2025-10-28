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

template <class T>
string bst<T>::to_string( void ) {
    
    
    ostringstream oss;
    
}
#endif