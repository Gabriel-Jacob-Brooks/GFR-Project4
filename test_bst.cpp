//Our Testing of BST

#include "iostream"
#include "usecase.cpp"
#include "string"
#include "sstream"
using namespace std;


void test_empty()
{
    try
    {
        BST<string, int> bst;
        if (!bst.empty())
        {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one", 1);
        if (bst.empty())
        {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if (bst_str != "1")
        {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for (int i = 2; i <= 10; i++)
        {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if (bst_str != "5 2 7 1 3 6 9 4 8 10")
        {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get()
{
    try
    {

        BST<string, int> bst;
        string val = bst.get(0);
        if (val != "")
        {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }

        bst.insert("one", 1);
        val = bst.get(1);
        if (val != "one")
        {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_successor()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if (succ != 5)
        {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if (succ != 8)
        {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if (succ != 0)
        {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if (bst_str != "5 2 8 1 3 6 9 4 10")
        {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}


void test_max_data()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if (max_str != "10 data")
        {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if (max_k != 10)
        {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

void test_min_data()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if (min_str != "1 data")
        {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if (min_k != 1)
        {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

void test_trim()
{
    try
    {
        BST<string, int> bst;
        int vals[3] = {1, 0, 2};
        for (int i = 0; i < 3; i++)
        {
            bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        bst.trim(1, 2);
        string bst_str = bst.to_string();
        if (bst_str != "1 2")
        {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for (int i = 0; i < 5; i++)
        {
            bst2.insert(to_string(vals2[i]) + " data", vals2[i]);
        }
        bst2.trim(1, 3);
        bst_str = bst2.to_string();
        if (bst_str != "3 2 1")
        {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_in_order()
{
    try
    {
        BST<string, int> bst;
        for (int i = 1; i <= 10; i++)
        {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

// Comprehensive test cases for to_string method
void test_to_string_normal()
{
    try
    {
        // Normal Case 1: Balanced BST with multiple nodes
        int vals[7] = {4, 2, 6, 1, 3, 5, 7};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 7; i++)
        {
            balanced_bst.insert("data" + to_string(vals[i]), vals[i]);
        }
        string bst_str = balanced_bst.to_string();
        if (bst_str != "4 2 6 1 3 5 7")
        {
            cout << "NORMAL CASE 1 FAILED: Expected '4 2 6 1 3 5 7' but got: " << bst_str << endl;
        }

        // Normal Case 2: Sequential insertion creating right-skewed tree
        BST<string, int> right_skewed;
        for (int i = 1; i <= 5; i++)
        {
            right_skewed.insert("node" + to_string(i), i);
        }
        bst_str = right_skewed.to_string();
        if (bst_str != "1 2 3 4 5")
        {
            cout << "NORMAL CASE 2 FAILED: Expected '1 2 3 4 5' but got: " << bst_str << endl;
        }

        // Normal Case 3: Reverse sequential insertion creating left-skewed tree
        BST<string, int> left_skewed;
        for (int i = 5; i >= 1; i--)
        {
            left_skewed.insert("node" + to_string(i), i);
        }
        bst_str = left_skewed.to_string();
        if (bst_str != "5 4 3 2 1")
        {
            cout << "NORMAL CASE 3 FAILED: Expected '5 4 3 2 1' but got: " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_to_string_normal: " << e.what() << endl;
    }
}

void test_to_string_edge()
{
    try
    {
        // Edge Case 1: Empty BST
        BST<string, int> empty_bst;
        string bst_str = empty_bst.to_string();
        if (bst_str != "")
        {
            cout << "EDGE CASE 1 FAILED: Expected empty string but got: '" << bst_str << "'" << endl;
        }

        // Edge Case 2: Single node
        BST<string, int> single_node;
        single_node.insert("only", 42);
        bst_str = single_node.to_string();
        if (bst_str != "42")
        {
            cout << "EDGE CASE 2 FAILED: Expected '42' but got: " << bst_str << endl;
        }

        // Edge Case 3: Two nodes (parent and left child)
        BST<string, int> two_nodes_left;
        two_nodes_left.insert("parent", 10);
        two_nodes_left.insert("left", 5);
        bst_str = two_nodes_left.to_string();
        if (bst_str != "10 5")
        {
            cout << "EDGE CASE 3 FAILED: Expected '10 5' but got: " << bst_str << endl;
        }

        // Edge Case 4: Two nodes (parent and right child)
        BST<string, int> two_nodes_right;
        two_nodes_right.insert("parent", 10);
        two_nodes_right.insert("right", 15);
        bst_str = two_nodes_right.to_string();
        if (bst_str != "10 15")
        {
            cout << "EDGE CASE 4 FAILED: Expected '10 15' but got: " << bst_str << endl;
        }

        // Edge Case 5: Three nodes (parent with both children)
        BST<string, int> three_nodes;
        three_nodes.insert("parent", 10);
        three_nodes.insert("left", 5);
        three_nodes.insert("right", 15);
        bst_str = three_nodes.to_string();
        if (bst_str != "10 5 15")
        {
            cout << "EDGE CASE 5 FAILED: Expected '10 5 15' but got: " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_to_string_edge: " << e.what() << endl;
    }
}

void test_to_string_boundary()
{
    try
    {
        // Boundary Case 1: Large tree with many levels
        BST<string, int> large_bst;
        int large_vals[15] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
        for (int i = 0; i < 15; i++)
        {
            large_bst.insert("data", large_vals[i]);
        }
        string bst_str = large_bst.to_string();
        if (bst_str != "8 4 12 2 6 10 14 1 3 5 7 9 11 13 15")
        {
            cout << "BOUNDARY CASE 1 FAILED: Expected '8 4 12 2 6 10 14 1 3 5 7 9 11 13 15' but got: " << bst_str << endl;
        }

        // Boundary Case 2: Negative keys
        BST<string, int> negative_keys;
        int neg_vals[7] = {0, -5, 5, -10, -2, 2, 10};
        for (int i = 0; i < 7; i++)
        {
            negative_keys.insert("data", neg_vals[i]);
        }
        bst_str = negative_keys.to_string();
        if (bst_str != "0 -5 5 -10 -2 2 10")
        {
            cout << "BOUNDARY CASE 2 FAILED: Expected '0 -5 5 -10 -2 2 10' but got: " << bst_str << endl;
        }

        // Boundary Case 3: All negative keys
        BST<string, int> all_negative;
        int all_neg_vals[5] = {-5, -8, -3, -10, -1};
        for (int i = 0; i < 5; i++)
        {
            all_negative.insert("data", all_neg_vals[i]);
        }
        bst_str = all_negative.to_string();
        if (bst_str != "-5 -8 -3 -10 -1")
        {
            cout << "BOUNDARY CASE 3 FAILED: Expected '-5 -8 -3 -10 -1' but got: " << bst_str << endl;
        }

    
    }
    catch (exception &e)
    {
        cerr << "Error in test_to_string_boundary: " << e.what() << endl;
    }
}

// Comprehensive test cases for in_order method
void test_in_order_normal()
{
    try
    {
        // Normal Case 1: Balanced BST should return sorted order
        int vals[7] = {4, 2, 6, 1, 3, 5, 7};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 7; i++)
        {
            balanced_bst.insert("data" + to_string(vals[i]), vals[i]);
        }
        string bst_str = balanced_bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7")
        {
            cout << "IN_ORDER NORMAL CASE 1 FAILED: Expected '1 2 3 4 5 6 7' but got: " << bst_str << endl;
        }

        // Normal Case 2: Right-skewed tree should still return sorted
        BST<string, int> right_skewed;
        for (int i = 1; i <= 5; i++)
        {
            right_skewed.insert("node" + to_string(i), i);
        }
        bst_str = right_skewed.in_order();
        if (bst_str != "1 2 3 4 5")
        {
            cout << "IN_ORDER NORMAL CASE 2 FAILED: Expected '1 2 3 4 5' but got: " << bst_str << endl;
        }

        // Normal Case 3: Left-skewed tree should still return sorted
        BST<string, int> left_skewed;
        for (int i = 5; i >= 1; i--)
        {
            left_skewed.insert("node" + to_string(i), i);
        }
        bst_str = left_skewed.in_order();
        if (bst_str != "1 2 3 4 5")
        {
            cout << "IN_ORDER NORMAL CASE 3 FAILED: Expected '1 2 3 4 5' but got: " << bst_str << endl;
        }

        // Normal Case 4: Random insertion order should still return sorted
        int random_vals[10] = {9, 3, 7, 1, 5, 10, 2, 8, 4, 6};
        BST<string, int> random_bst;
        for (int i = 0; i < 10; i++)
        {
            random_bst.insert("data", random_vals[i]);
        }
        bst_str = random_bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "IN_ORDER NORMAL CASE 4 FAILED: Expected '1 2 3 4 5 6 7 8 9 10' but got: " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_in_order_normal: " << e.what() << endl;
    }
}

void test_in_order_edge()
{
    try
    {
        // Edge Case 1: Empty BST
        BST<string, int> empty_bst;
        string bst_str = empty_bst.in_order();
        if (bst_str != "")
        {
            cout << "IN_ORDER EDGE CASE 1 FAILED: Expected empty string but got: '" << bst_str << "'" << endl;
        }

        // Edge Case 2: Single node
        BST<string, int> single_node;
        single_node.insert("only", 42);
        bst_str = single_node.in_order();
        if (bst_str != "42")
        {
            cout << "IN_ORDER EDGE CASE 2 FAILED: Expected '42' but got: " << bst_str << endl;
        }

        // Edge Case 3: Two nodes
        BST<string, int> two_nodes;
        two_nodes.insert("second", 20);
        two_nodes.insert("first", 10);
        bst_str = two_nodes.in_order();
        if (bst_str != "10 20")
        {
            cout << "IN_ORDER EDGE CASE 3 FAILED: Expected '10 20' but got: " << bst_str << endl;
        }

        // Edge Case 4: Three nodes in perfect balance
        BST<string, int> three_nodes;
        three_nodes.insert("middle", 10);
        three_nodes.insert("left", 5);
        three_nodes.insert("right", 15);
        bst_str = three_nodes.in_order();
        if (bst_str != "5 10 15")
        {
            cout << "IN_ORDER EDGE CASE 4 FAILED: Expected '5 10 15' but got: " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_in_order_edge: " << e.what() << endl;
    }
}

void test_in_order_boundary()
{
    try
    {
        // Boundary Case 1: Large tree
        BST<string, int> large_bst;
        int large_vals[15] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
        for (int i = 0; i < 15; i++)
        {
            large_bst.insert("data", large_vals[i]);
        }
        string bst_str = large_bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15")
        {
            cout << "IN_ORDER BOUNDARY CASE 1 FAILED: Expected '1 2 3 4 5 6 7 8 9 10 11 12 13 14 15' but got: " << bst_str << endl;
        }

        // Boundary Case 2: Negative keys
        BST<string, int> negative_keys;
        int neg_vals[7] = {0, -5, 5, -10, -2, 2, 10};
        for (int i = 0; i < 7; i++)
        {
            negative_keys.insert("data", neg_vals[i]);
        }
        bst_str = negative_keys.in_order();
        if (bst_str != "-10 -5 -2 0 2 5 10")
        {
            cout << "IN_ORDER BOUNDARY CASE 2 FAILED: Expected '-10 -5 -2 0 2 5 10' but got: " << bst_str << endl;
        }

        // Boundary Case 3: All negative keys
        BST<string, int> all_negative;
        int all_neg_vals[5] = {-5, -8, -3, -10, -1};
        for (int i = 0; i < 5; i++)
        {
            all_negative.insert("data", all_neg_vals[i]);
        }
        bst_str = all_negative.in_order();
        if (bst_str != "-10 -8 -5 -3 -1")
        {
            cout << "IN_ORDER BOUNDARY CASE 3 FAILED: Expected '-10 -8 -5 -3 -1' but got: " << bst_str << endl;
        }

        // Boundary Case 4: Very long chain (stress test)
        BST<string, int> long_chain;
        for (int i = 20; i >= 1; i--)
        {
            long_chain.insert("node", i);
        }
        bst_str = long_chain.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20")
        {
            cout << "IN_ORDER BOUNDARY CASE 4 FAILED: Expected '1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20' but got: " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_in_order_boundary: " << e.what() << endl;
    }
}

// Comprehensive test cases for usecase functions
void test_usecase_normal()
{
    try
    {
        // Normal Case 1: Create a simple binary-to-hex mapping BST and convert
        BST<string, string> hex_bst;
        hex_bst.insert("0", "0000");
        hex_bst.insert("1", "0001");
        hex_bst.insert("2", "0010");
        hex_bst.insert("3", "0011");
        hex_bst.insert("4", "0100");
        hex_bst.insert("5", "0101");
        hex_bst.insert("6", "0110");
        hex_bst.insert("7", "0111");
        hex_bst.insert("8", "1000");
        hex_bst.insert("9", "1001");
        hex_bst.insert("A", "1010");
        hex_bst.insert("B", "1011");
        hex_bst.insert("C", "1100");
        hex_bst.insert("D", "1101");
        hex_bst.insert("E", "1110");
        hex_bst.insert("F", "1111");

        // Test convert function - Normal Case 1: Simple 4-bit conversion
        string result = convert(&hex_bst, "1111");
        if (result != "F")
        {
            cout << "USECASE NORMAL CASE 1 FAILED: Expected 'F' but got: " << result << endl;
        }

        // Normal Case 2: 8-bit conversion
        result = convert(&hex_bst, "11111111");
        if (result != "FF")
        {
            cout << "USECASE NORMAL CASE 2 FAILED: Expected 'FF' but got: " << result << endl;
        }

        // Normal Case 3: Mixed binary pattern
        result = convert(&hex_bst, "10100101");
        if (result != "A5")
        {
            cout << "USECASE NORMAL CASE 3 FAILED: Expected 'A5' but got: " << result << endl;
        }

        // Normal Case 4: All zeros
        result = convert(&hex_bst, "00000000");
        if (result != "00")
        {
            cout << "USECASE NORMAL CASE 4 FAILED: Expected '00' but got: " << result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_usecase_normal: " << e.what() << endl;
    }
}

void test_usecase_edge()
{
    try
    {
        // Create hex BST for edge cases
        BST<string, string> hex_bst;
        hex_bst.insert("0", "0000");
        hex_bst.insert("1", "0001");
        hex_bst.insert("2", "0010");
        hex_bst.insert("3", "0011");
        hex_bst.insert("4", "0100");
        hex_bst.insert("5", "0101");
        hex_bst.insert("6", "0110");
        hex_bst.insert("7", "0111");
        hex_bst.insert("8", "1000");
        hex_bst.insert("9", "1001");
        hex_bst.insert("A", "1010");
        hex_bst.insert("B", "1011");
        hex_bst.insert("C", "1100");
        hex_bst.insert("D", "1101");
        hex_bst.insert("E", "1110");
        hex_bst.insert("F", "1111");

        // Edge Case 1: Single bit (requires padding)
        string result = convert(&hex_bst, "1");
        if (result != "1")
        {
            cout << "USECASE EDGE CASE 1 FAILED: Expected '1' but got: " << result << endl;
        }

        // Edge Case 2: Two bits (requires padding)
        result = convert(&hex_bst, "10");
        if (result != "2")
        {
            cout << "USECASE EDGE CASE 2 FAILED: Expected '2' but got: " << result << endl;
        }

        // Edge Case 3: Three bits (requires padding)
        result = convert(&hex_bst, "111");
        if (result != "7")
        {
            cout << "USECASE EDGE CASE 3 FAILED: Expected '7' but got: " << result << endl;
        }

        // Edge Case 4: Exactly 4 bits (no padding needed)
        result = convert(&hex_bst, "1010");
        if (result != "A")
        {
            cout << "USECASE EDGE CASE 4 FAILED: Expected 'A' but got: " << result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_usecase_edge: " << e.what() << endl;
    }
}

void test_usecase_boundary()
{
    try
    {
        // Create hex BST for boundary cases
        BST<string, string> hex_bst;
        hex_bst.insert("0", "0000");
        hex_bst.insert("1", "0001");
        hex_bst.insert("2", "0010");
        hex_bst.insert("3", "0011");
        hex_bst.insert("4", "0100");
        hex_bst.insert("5", "0101");
        hex_bst.insert("6", "0110");
        hex_bst.insert("7", "0111");
        hex_bst.insert("8", "1000");
        hex_bst.insert("9", "1001");
        hex_bst.insert("A", "1010");
        hex_bst.insert("B", "1011");
        hex_bst.insert("C", "1100");
        hex_bst.insert("D", "1101");
        hex_bst.insert("E", "1110");
        hex_bst.insert("F", "1111");

        // Boundary Case 1: Long binary string (16 bits = 4 hex digits)
        string result = convert(&hex_bst, "1111000011110000");
        if (result != "F0F0")
        {
            cout << "USECASE BOUNDARY CASE 1 FAILED: Expected 'F0F0' but got: " << result << endl;
        }

        // Boundary Case 2: Very long binary string (32 bits = 8 hex digits)
        result = convert(&hex_bst, "11010110101111001011110011011011");
        if (result != "D6BCBCDB")
        {
            cout << "USECASE BOUNDARY CASE 2 FAILED: Expected 'D6BCBCDB' but got: " << result << endl;
        }

        // Boundary Case 3: 5 bits (needs padding to 8 bits = 2 hex)
        result = convert(&hex_bst, "10101");
        if (result != "15")
        {
            cout << "USECASE BOUNDARY CASE 3 FAILED: Expected '15' but got: " << result << endl;
        }

        // Boundary Case 4: Maximum single hex digit value
        result = convert(&hex_bst, "1111");
        if (result != "F")
        {
            cout << "USECASE BOUNDARY CASE 4 FAILED: Expected 'F' but got: " << result << endl;
        }

        // Boundary Case 5: Minimum single hex digit value
        result = convert(&hex_bst, "0000");
        if (result != "0")
        {
            cout << "USECASE BOUNDARY CASE 5 FAILED: Expected '0' but got: " << result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in test_usecase_boundary: " << e.what() << endl;
    }
}

int main()
{
    // Original test functions
    test_empty();
    test_insert();
    test_remove();
    test_successor();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_get();
    test_in_order();
    test_trim();

    // Comprehensive test cases for to_string method
    test_to_string_normal();
    test_to_string_edge();
    test_to_string_boundary();

    // Comprehensive test cases for in_order method
    test_in_order_normal();
    test_in_order_edge();
    test_in_order_boundary();

    // Comprehensive test cases for usecase functions
    test_usecase_normal();
    test_usecase_edge();
    test_usecase_boundary();

    cout << "All tests completed!" << endl;
}