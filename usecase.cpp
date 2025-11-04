//usecase.cpp
#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class D, class K>
BST<D,K>* create_bst(string filename) {
    BST<D,K>* bst = new BST<D,K>();
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t comma = line.find(',');
        D hex = line.substr(0, comma);
        K binary = line.substr(comma + 1);
        bst->insert(hex, binary);
    }
    return bst;
}

template<class D, class K>
D convert(BST<D,K>* bst, string binary) {
    string result = "";
    
    // Pad the binary string to make it a multiple of 4 from the LEFT
    int remainder = binary.length() % 4;
    if (remainder != 0) {
        binary = string(4 - remainder, '0') + binary;
    }
    
    // Process from left to right (which represents right-to-left in significance)
    for (int i = 0; i < binary.length(); i += 4) {
        string chunk = binary.substr(i, 4);
        result += bst->get(chunk);
    }
    
    return result;
}