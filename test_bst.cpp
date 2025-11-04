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
        //When creating a BST it should be empty.
        if (!bst.empty())
        {
            cout << "Incorrect empty result." << endl;
        }
        //Insert something int BST should make empty() false
        bst.insert("one", 1);
        if (bst.empty())
        {
            cout << "Incorrect empty result." << endl;
        }
        //Test if it still will read empty if we remove something
        bst.remove(1);
        if (!bst.empty())
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
        // Testing Insert on an Unbalenced tree
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
        //Testing insert on a balance tree
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
        // Getting/Ablitiy to insert Strings
        bst.insert("one", 1);
        val = bst.get(1);
        if (val != "one")
        {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
        // Getting/Ablitiy to insert Ints with int key
        BST<int, int> bst_int;
        bst_int.insert(65, 1);
        int valint = bst_int.get(1);
        if (valint != 65)
        {
            cout << "Incorrect get result. Expected 65 but got : " << valint << endl;
        }
        // Getting/Ablitiy to insert long
        BST<long, long> bst_long;
        bst_int.insert(70.0, 2.0);
        long vallong = bst_int.get(2.0);
        if (vallong != 70.0)
        {
            cout << "Incorrect get result. Expected 70.0 but got : " << vallong << endl;
        }
        // Getting/Ablitiy to insert char with char key
        BST<char, char> bst_char;
        bst_char.insert('d', 'a');
        long valchar = bst_char.get('a');
        if (valchar != 'd')
        {
            cout << "Incorrect get result. Expected 'd' but got : " << valchar << endl;
        }
        // Getting/Ablitiy to insert float with float key
        BST<float, float> bst_float;
        bst_float.insert(4.0f, 1.0f);
        float valfloat = bst_float.get(1.0f);
        if (valfloat != 4.0f)
        {
            cout << "Incorrect get result. Expected 'd' but got : " << valfloat << endl;
        }
        // Getting/Ablitiy to insert bool with int key
        BST<bool, int> bst_bool;
        bst_bool.insert(true, 1);
        long valbool = bst_bool.get(1);
        if (valbool != true)
        {
            cout << "Incorrect get result. Expected 'd' but got : " << valbool << endl;
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
        //Test to see removing from a balanced tree
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
        //Test to see if we can remove from an empty BST
        BST<string, int> empty_bst;
        empty_bst.remove(1);

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

int main()
{
    cout << endl
         << "Running tests for our test file" << endl
         << endl;

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

    cout << "Testing completed" << endl;
}