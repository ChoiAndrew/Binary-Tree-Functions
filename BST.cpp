/*
   Author: Andrew Choi
    Date: April 20 2020
    Purpose: BST class is to create a binary search tree and store numbers from the three 
                    txt files. Program should find the smallest branch height, Highest branch heigh,
                   number of nodes, balance of the tree, and completeness of the tree
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int input)
{
    Node* node = new Node;
    node->data = input;
    node->left  = nullptr;
    node->right = nullptr;

    return node;
}

//maxBranch: Helper function for heightOfTree function
int maxBranch(int num1, int num2)
{
    return (num1 >= num2) ? num1 : num2;
}

//heightOfTree: Helper function to determine if tree is balanced
int heightOfTree(Node* inputNode)
{
    if (inputNode == nullptr)
        return 0;

    return 1 + maxBranch(heightOfTree(inputNode->left),
        heightOfTree(inputNode->right));
}

//isBalanced: Determines if a tree is balanced recursively
bool isBalanced(Node* root)
{
    int leftSide;
    int rightSide; 

    if (root == nullptr)
        return 1;

    leftSide = heightOfTree(root->left);
    rightSide = heightOfTree(root->right);

    if (abs(leftSide - rightSide) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

//display: Prints tree inorder traversal
void display(Node* root)
{
    if (root == nullptr)
        return;

    display(root->left);
    //print left side
    cout << root->data << " ";
    display(root->right);
    //print right side
}

//count: counts the number of nodes in the BST
int count(Node* root)
{
    if (root == nullptr)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

//insert: adds a new node to the BST with a given input
Node* insert(Node* root, int input)
{
    if (root == nullptr)
        return newNode(input);

    if (input < root->data)
        root->left = insert(root->left, input);

    else
        root->right = insert(root->right, input);

    return root;
}

//maxBranchHeight: FInds the max branch height of the BST
int maxBranchHeight(Node* tree)
{
    if (tree == nullptr)
        return 0;

        int leftHeight = maxBranchHeight(tree->left);
        int rightHeight = maxBranchHeight(tree->right);

        if (leftHeight > rightHeight)
            return(leftHeight + 1);

        else
            return(rightHeight + 1);
}

//minBranchHeight: FInds the min branch height of BST
int minBranchHeight(Node* tree)
{
    if (tree == nullptr)
        return 0;

        int leftHeight = minBranchHeight(tree->left);
        int rightHeight = minBranchHeight(tree->right);

        if (leftHeight < rightHeight)
            return(leftHeight + 1);

        else 
            return(rightHeight + 1);
    
}

//completeTreeL check to see if tree is complete
bool completeTree(struct Node* baseNode)
{
    if (baseNode == nullptr)
        return true;

    if (baseNode->left == nullptr && baseNode->right == nullptr)
        return true;

    if ((baseNode->left) && (baseNode->right))
        return (completeTree(baseNode->left) && completeTree(baseNode->right));

    return false;
}

//Driver to test the three txt files
int main()
{
    //First Text File
      Node* root = nullptr;
    string output;
    ifstream myfile("CSS343_A1_F1.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, output);
            stringstream geek(output);
            int x = 0;
            geek >> x;

            root = insert(root, x);
        }
        myfile.close();
        cout << "Tree Data: ";
        display(root);
        cout << endl;

        cout << "Smallest Branch Height: " << minBranchHeight(root) << endl;
        cout << "Highest Branch Heightt: " << maxBranchHeight(root) << endl;
        cout << "Number of nodes: " << count(root) << endl;

        if (isBalanced(root))
            cout << "Is the BST balanced: " << " True" << endl;
        else
            cout << "Is the BST balanced: " << "False" << endl;

        if (completeTree(root))
            cout << "Is BST Complete: " << "True" << endl;
        else
            cout << "Is BST Complete: " << "False" << endl;


        cout << "------------------------------------------------------" << endl;

        }
    else cout << "Unable to open file";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Second text file
    Node* root1 = nullptr;
    string output1;
    ifstream myfile1("CSS343_A1_F2.txt");
    if (myfile1.is_open())
    {
        while (!myfile1.eof())
        {
            getline(myfile1, output1);
            stringstream geek(output1);
            int x = 0;
            geek >> x;

            root1 = insert(root1, x);
        }
        myfile1.close();
        cout << "Tree Data: ";
        display(root1);
        cout << endl;

        cout << "Smallest Branch Height: " << minBranchHeight(root1) << endl;
        cout << "Highest Branch Heightt: " << maxBranchHeight(root1) << endl;
        cout << "Number of nodes: " << count(root1) << endl;

        if (isBalanced(root1))
            cout << "Is the BST balanced: " << " True" << endl;
        else
            cout << "Is the BST balanced: " << "False" << endl;

        if (completeTree(root1))
            cout << "Is BST Complete: " << "True" << endl;
        else
            cout << "Is BST Complete: " << "False" << endl;


        cout << "------------------------------------------------------" << endl;

    }
    else cout << "Unable to open file";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Thrid text file
    Node* root2 = nullptr;
    string output2;
    ifstream myfile2("CSS343_A1_F3.txt");
    if (myfile2.is_open())
    {
        while (!myfile2.eof())
        {
            getline(myfile2, output2);
            stringstream geek(output2);
            int x = 0;
            geek >> x;

            root2 = insert(root2, x);
        }
        myfile2.close();
        cout << "Tree Data: ";
        display(root2);
        cout << endl;

        cout << "Smallest Branch Height: " << minBranchHeight(root2) << endl;
        cout << "Highest Branch Height: " << maxBranchHeight(root2) << endl;
        cout << "Number of nodes: " << count(root2) << endl;

        if (isBalanced(root2))
            cout << "Is the BST balanced: " << " True" << endl;
        else
            cout << "Is the BST balanced: " << "False" << endl;

        if (completeTree(root2))
            cout << "Is BST Complete: " << "True" << endl;
        else
            cout << "Is BST Complete: " << "False" << endl;


        cout << "------------------------------------------------------" << endl;

    }
    else cout << "Unable to open file";



    return 0;
    
}
