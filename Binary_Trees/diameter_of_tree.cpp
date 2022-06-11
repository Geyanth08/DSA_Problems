// Leetcode link - https://leetcode.com/problems/diameter-of-binary-tree/
// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Calculate left and right height of a node -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    int height(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;

        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};