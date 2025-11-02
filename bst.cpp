//====================================================
// bst.cpp
//
// Created by Gabe, Ramatu, and Phlynn
//====================================================

#include "iostream"
#include "queue"
#include "string"
#include "sstream"
using namespace std;

#ifndef BST_CPP
#define BST_CPP
#include "bst.h"

//====================================================
// BST FUNCTIONS
//====================================================

template <class D, class K>
bst<D, K>::bst() {
    root=nullptr;
}


template <class D, class K>
bst<D, K>::~bst() {
    clear(root);
}

template <class D, class K>
void bst<D, K>::clear(Node* node) {
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
bool bst<D, K>::empty() {
    return root == nullptr;
}

//==========================================================
// insert
// inserts key k into a valid bst
// parameters: T& d - element's template data
//             const long& k - numeric key value
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
void bst<D, K>::insert( const D& d, const K&  k ) {
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
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
D bst<D, K>::get( const K&  k ) {
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
    return D();

}

//==========================================================
// remove 
// deletes the first node it finds with key k (closest to root)
// parameters: long k - numeric key value
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
void bst<D, K>::remove( K k ) {
    
    Node* curr = root;

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
template <class D, class K>
K bst<D, K>::max_data( void ) {
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
template <class D, class K>
K bst<D, K>::max_key( void ) {

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
template <class D, class K>
K bst<D, K>::min_data( void ) {
    Node* min = root.min_key(); // retreives key not data fix
    return min->data;

}
//==========================================================
// min_key
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
K bst<D, K>::min_key( void ) {
    Node* curr = root;

    while (curr->left != nullptr)
        curr = curr->left;

    return curr->key;
}
// ==========================================================
// successor

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
void bst<T>::transplant( Node *x, Node *y) {
    if (x->parent == nullptr) // end to check logic
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else (x->parent->right = y);
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
// ==========================================================
template <class D, class K>
K bst<D, K>::successor( K k ) {
    Node* x = nullptr;
    x = root;
    if (get(k) != NULL){
        if(x->right != nullptr){
            x = x->right;
            while(x->left != nullptr){
                x = x->left;
            }
            return x->key;
        }else{
            while(x->key < k){
                x->parent;
            }
            return x->key;
        }
    } else {
        return 0;
    }
}

// //==========================================================
// // in_order
// // 
// // parameters: none
// // pre-condition: 
// // post-condition: 
// //==========================================================
// template <class T>
// long bst<T>::in_order( void ) {
template <class D, class K>
string BST<D, K>::in_order() {
    ostringstream oss;                 // Move here, not static
    in_order_helper(root, oss);    // Pass first as reference
    return oss.str();
}

template <class D, class K>
void BST<D, K>::in_order_helper(Node* node, ostringstream& oss) {
    if (node == nullptr) return;
    
    in_order_helper(node->left, oss);     // Pass first along
    if (!first) oss << " ";
    oss << node->key;
    first = false;
    in_order_helper(node->right, oss);    // Pass first along
}


// }

// //==========================================================
// // trim
// // 
// // parameters:  long low - 
// //              long high - 
// // pre-condition: 
// // post-condition: 
// //==========================================================
// template <class T>
// void bst<T>::trim( long low, long high ) {

  
// }

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
