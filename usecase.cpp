//usecase.cpp
#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class T, class K>
BST<T,K>* create_bst(string filename) {
    BST<T,K>* bst = new BST<T,K>();
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t comma = line.find(',');
        T hex = line.substr(0, comma);
        K binary = line.substr(comma + 1);
        bst->insert(hex, binary);
    }
    return bst;
}

template<class T, class K>
T convert(BST<T,K>* bst, string binary) {
    string result = "";
    for (int i = 0; i < binary.length(); i += 4) {
        string chunk = binary.substr(i, 4);
        result += bst->get(chunk);
    }
    return result;
}
