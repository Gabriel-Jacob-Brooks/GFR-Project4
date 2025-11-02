// CS271 Binary Search Header File

// Created by Gabe, Ramatu, and Phlynn


#ifndef BST_H
#define BST_H
#include "iostream"
#include "cmath"
#include "string"
#include "queue"
#include "sstream"
using namespace std;

//==========================================================
template <class D, class K>
class BST {
private:
    struct Node {
        D data;
        K key;
        Node* left;
        Node* right;
        Node* parent;
        Node(D d, K k) : data(d), key(k), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    
    Node* root;
public:
    BST(); //instantiate
    ~BST(); // destructor
    void clear(Node* node);
    bool empty(); // checks if its empty
    void insert (const D& d, const K&  k);
    D get (const K&  k); //returns data associated with key k. // Might be implemented in other DLL???
    void remove (K k);
    D max_data();
    K max_key();
    D min_data();
    K min_key();
    K successor(K k);
    K in_order();
    void in_order_helper(Node* node, ostringstream& oss);
    void transplant ( Node *x, Node *y);
    void trim(long low, long high);
    string to_string();

};


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
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
void BST<D, K>::insert( const D& d, const K&  k ) {
    Node* z = new Node(d, k);
    Node* x = root;
    Node* y = nullptr;
    {
        while(x != nullptr){
            y = x;
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
            return;
        }
        else{
            y->right = z;
            return;
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
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
void BST<D, K>::remove( K k ) {
    
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

template <class D, class K>
void BST<D, K>::transplant( Node *x, Node *y) {
    if (x->parent == nullptr) // end to check logic
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else (x->parent->right = y);
    if ( y == nullptr )
        y->parent = x->parent;

}
//==========================================================
// max_data
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
D BST<D, K>::max_data( void ) {

    Node* curr = root;

    while (curr -> right != nullptr)
        curr = curr -> right;

    return curr -> data;

    // D max = root.max_key(); // retreive key not data fix 
    // return max;
}


//==========================================================
// max_key
// 
// parameters: none
// pre-condition: 
// post-condition: 
//==========================================================
template <class D, class K>
K BST<D, K>::max_key( void ) {

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
D BST<D, K>::min_data( void ) {
    Node* curr = root;

    while (curr->left != nullptr)
        curr = curr->left;

    return curr -> data;
    // D min = root.min_key(); // retreives key not data fix
    // return min;
}
//==========================================================
// min_key
// 
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

// parameters: V k - numeric key value
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

// //==========================================================
// // in_order
// // 
// // parameters: none
// // pre-condition: 
// // post-condition: 
// //==========================================================
// template <class T>
// long bst<T>::in_order( void ) {


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

#endif