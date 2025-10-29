// CS271 Binary Search Header File

// Created by Gabe, Ramatu, and Phlynn


#ifndef BST_H
#define BST_H
#include "iostream"
#include "cmath"
#include "string"
using namespace std;

//==========================================================
template <class T>
class bst {
private:
    struct Node {
        T data;
        long key;
        Node* left;
        Node* right;
        Node* parent;
        Node(T d, long k) : data(d), key(k), left(nullptr), right(nullptr), parent(nullptr) {}

    };
    
    Node* root;
public:
    bst(); //instantiate
    ~bst(); // destructor
    bool empty(); // checks if its empty
    void insert (const T& d, const long&  k);
    long get (const long&  k); //returns data associated with key k. // Might be implemented in other DLL???
    void remove (long k);
    long max_data();
    long max_key();
    long min_data();
    long min_key();
    long successor(long k);
    long in_order();
    void trim(long low, long high);
    string to_string();

};



#endif