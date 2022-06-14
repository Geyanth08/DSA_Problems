// Practice link - https://practice.geeksforgeeks.org/problems/mirror-tree/1#
// Given a Binary Tree, convert it into its mirror.

#include <bits/stdc++.h>
using namespace std;

// Create a Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// In Mirror root remains same, left becomes right, right becomes left -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void buildMirrorTree(struct Node *root)
    {
        if (root == NULL)
            return;

        swap(root->left, root->right);

        buildMirrorTree(root->left);
        buildMirrorTree(root->right);
    }
    void mirror(Node *node)
    {
        if (node == NULL)
            return;

        buildMirrorTree(node);
    }
};
