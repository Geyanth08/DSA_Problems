// Write a program to print path from root to a given node in a binary tree.

#include <bits/stdc++.h>
using namespace std;

// Creating a Node in Binary Tree
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function Declaration
vector<int> solve(Node *root, int nodeValue);
bool getPath(Node *root, int val, vector<int> &path);

// Main Function
int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    // Creating above Binary Tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int value = 6;

    vector<int> path = solve(root, value);
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}

// Using Inorder Traversal and Recursion -> Time Complexity - O(N), Space Complexity - O(N)
vector<int> solve(Node *root, int nodeValue)
{
    vector<int> path;
    if (root == NULL)
        return path;

    getPath(root, nodeValue, path);

    return path;
}

bool getPath(Node *root, int val, vector<int> &path)
{
    if (!root)
        return false;

    path.push_back(root->data);

    if (root->data == val)
        return true;

    if (getPath(root->left, val, path) or getPath(root->right, val, path))
        return true;

    path.pop_back();
    return false;
}