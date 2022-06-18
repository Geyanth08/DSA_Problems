// Leetcode link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Using Inorder Traversal -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    TreeNode *inorder(TreeNode *root, int &k)
    {
        if (root == NULL)
            return NULL;
        TreeNode *left = inorder(root->left, k);

        if (left != NULL)
            return left;
        k--;
        if (k == 0)
            return root;

        return inorder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *small = inorder(root, k);
        return small->val;
    }
};