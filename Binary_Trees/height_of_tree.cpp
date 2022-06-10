// Leetcode link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Height / Depth of the Binary Tree

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
int height(struct Node *root);

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

    // Height (levels) : 3
    cout << height(root);

    return 0;
}

// Using Recursion -> Time Complexity - O(n), Space Complexity - O(n)
int height(struct Node *root)
{

    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}