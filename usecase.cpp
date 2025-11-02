//usecase.cpp
#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Creates BST from file with hex,binary pairs
template<class T, class K>
BST<T,K>* create_bst(string filename) {
    BST<T,K>* bst = new BST<T,K>();
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t comma = line.find(',');      // Find comma separator
        T hex = line.substr(0, comma);      // Extract hex digit
        K binary = line.substr(comma + 1);  // Extract binary code
        bst->insert(hex, binary);           // Insert with binary as key
    }
    return bst;
}

// Converts binary string to hex using BST lookup
template<class T, class K>
T convert(BST<T,K>* bst, string binary) {
    string result = "";
    for (int i = 0; i < binary.length(); i += 4) {  // Process 4 bits chunks
        string chunk = binary.substr(i, 4);         // Extract 4-bit substring
        result += bst->get(chunk);                  // Lookup hex digit
    }
    return result;
}
