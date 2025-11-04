//main.cpp
#include "iostream"
#include "usecase.cpp"
#include "string"
#include "sstream"

using namespace std;

int main(){
    cout << "=== BST Demonstration ===" << endl << endl;

    // Example 1: Using to_string with a balanced BST
    cout << "Example 1: to_string method (Level-order traversal)" << endl;
    BST<string, int> demo_bst1;
    int vals1[7] = {4, 2, 6, 1, 3, 5, 7};
    for (int i = 0; i < 7; i++) {
        demo_bst1.insert("data" + to_string(vals1[i]), vals1[i]);
    }
    cout << "Inserted keys: {4, 2, 6, 1, 3, 5, 7}" << endl;
    cout << "to_string output: " << demo_bst1.to_string() << endl;
    cout << endl;

    // Example 2: Using in_order method
    cout << "Example 2: in_order method (Sorted traversal)" << endl;
    BST<string, int> demo_bst2;
    int vals2[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
    for (int i = 0; i < 10; i++) {
        demo_bst2.insert("node" + to_string(vals2[i]), vals2[i]);
    }
    cout << "Inserted keys: {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}" << endl;
    cout << "in_order output: " << demo_bst2.in_order() << endl;
    cout << "to_string output: " << demo_bst2.to_string() << endl;
    cout << endl;

    // Example 3: Using usecase functions for binary-to-hex conversion
    cout << "Example 3: Binary to Hexadecimal Conversion (usecase)" << endl;
    BST<string, string>* hex_bst = create_bst<string, string>("binhex.txt");

    string binary1 = "11111111";
    cout << "Binary: " << binary1 << " -> Hex: " << convert(hex_bst, binary1) << endl;

    string binary2 = "10100101";
    cout << "Binary: " << binary2 << " -> Hex: " << convert(hex_bst, binary2) << endl;

    string binary3 = "1111000011110000";
    cout << "Binary: " << binary3 << " -> Hex: " << convert(hex_bst, binary3) << endl;

    string binary4 = "111";
    cout << "Binary: " << binary4 << " (padded) -> Hex: " << convert(hex_bst, binary4) << endl;

    delete hex_bst;  // Clean up the dynamically allocated BST
    cout << endl;

    // Example 4: Comparing to_string vs in_order on skewed trees
    cout << "Example 4: Right-skewed tree comparison" << endl;
    BST<string, int> right_skewed;
    for (int i = 1; i <= 5; i++) {
        right_skewed.insert("node" + to_string(i), i);
    }
    cout << "Inserted keys sequentially: {1, 2, 3, 4, 5}" << endl;
    cout << "to_string (level-order): " << right_skewed.to_string() << endl;
    cout << "in_order (sorted): " << right_skewed.in_order() << endl;
    cout << endl;

    cout << "Example 5: Left-skewed tree comparison" << endl;
    BST<string, int> left_skewed;
    for (int i = 5; i >= 1; i--) {
        left_skewed.insert("node" + to_string(i), i);
    }
    cout << "Inserted keys reverse: {5, 4, 3, 2, 1}" << endl;
    cout << "to_string (level-order): " << left_skewed.to_string() << endl;
    cout << "in_order (sorted): " << left_skewed.in_order() << endl;
    cout << endl;

    // Example 6: Empty and single node edge cases
    cout << "Example 6: Edge cases" << endl;
    BST<string, int> empty_bst;
    cout << "Empty BST to_string: '" << empty_bst.to_string() << "'" << endl;
    cout << "Empty BST in_order: '" << empty_bst.in_order() << "'" << endl;

    BST<string, int> single_node;
    single_node.insert("only", 42);
    cout << "Single node (42) to_string: " << single_node.to_string() << endl;
    cout << "Single node (42) in_order: " << single_node.in_order() << endl;
    cout << endl;

    cout << "=== End of Demonstration ===" << endl;

    return 0;
}