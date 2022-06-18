// Practice link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#
// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

#include <bits/stdc++.h>
using namespace std;

// Create Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Using Inorder Traversal -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    Node *inorder(Node *root, int &k)
    {
        if (root == NULL)
            return NULL;

        Node *right = inorder(root->right, k);
        if (right != NULL)
            return right;

        k--;
        if (k == 0)
            return root;

        return inorder(root->left, k);
    }
    int kthLargest(Node *root, int K)
    {
        Node *large = inorder(root, K);
        return large->data;
    }
};