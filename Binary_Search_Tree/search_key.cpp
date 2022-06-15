// Leetcode link - https://leetcode.com/problems/search-in-a-binary-search-tree/
// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

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

// Traverse as we do in binary search -> Time Complexity - O(logN), Space Complexity - O(1)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL and root->val != val)
        {
            root = val < root->val ? root->left : root->right;
        }

        return root;
    }
};