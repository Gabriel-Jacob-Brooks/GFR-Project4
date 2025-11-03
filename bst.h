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
    string in_order();
    void in_order_helper(Node* node, ostringstream& oss);
    void transplant ( Node *x, Node *y);
    void trim(K low, K high);
    Node* trim_helper(Node* node, K low, K high);
    string to_string();

};


//====================================================
// BST FUNCTIONS
//====================================================


# include "bst.cpp"
#endif