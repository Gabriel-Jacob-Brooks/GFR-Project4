// CS271 Binary Search Header File

// Created by Gabe, Ramatu, and Phlynn


#ifndef BST_H
#define BST_H

#include "iostream"
#include "cmath"
using namespace std;

//==========================================================
template <class T>
class bst {
private:
    int size; //size of T array 
    DoublyLinkedList<T>* table;

public:
    bst(int m); //instantiate
    ~bst(); // destructor
    void empty(); // checks if its empty
    void insert (const T& d, const long&  k);
    bool get (const long&  k); //returns data associated with key k. // Might be implemented in other DLL???
    void remove (long k);
    void max_data();
    void max_key();
    void min_data();
    void min_key();
    void successor(long k);
    void in_order();
    void trim(long low, long high);


};

#include "bst.cpp"

#endif