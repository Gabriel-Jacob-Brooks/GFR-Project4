//usecase.cpp
#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class D, class K>
BST<D,K>* create_bst(string filename) {
    BST<D,K>* bst = new BST<D,K>();
    ifstream file(filename); //reads file in
    string line;
    while (getline(file, line)) {
        size_t comma = line.find(',');
        D hex = line.substr(0, comma); //Does first part of line till comma and puts it into hex
        K binary = line.substr(comma + 1); //Does after the comma and puts it into binary
        bst->insert(hex, binary); // Hex is the data, binary is the key.
    }
    return bst;
}


template<class D, class K>
D convert(BST<D,K>* bst, string binary) {
    string result = "";
    
    // Pad the binary string to make it a multiple of 4 from the LEFT
    int remainder = binary.length() % 4; // We get the remainder in order to add the 00s on the front.
    if (remainder != 0) {
        binary = string(4 - remainder, '0') + binary; // We put the amount of 0's needed on front of binary
    }
    
    // Process from left to right (which represents right-to-left in significance)
    for (int i = 0; i < binary.length(); i += 4) { //Iterate through the string of binary
        string chunk = binary.substr(i, 4); //get a chunk of 4 to use as key in BST
        result += bst->get(chunk); //add the data of correct hex to the result.
    }
    
    return result;
}