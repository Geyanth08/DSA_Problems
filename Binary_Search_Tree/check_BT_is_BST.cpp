// Leetcode link - https://leetcode.com/problems/validate-binary-search-tree/
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

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

// Find the Range of a Node and check -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    bool check(TreeNode *root, TreeNode *lowerBound, TreeNode *upperBound)
    {
        if (root == NULL)
            return true;
        if ((upperBound and (root->val >= upperBound->val)) or (lowerBound and (root->val <= lowerBound->val)))
            return false;

        return check(root->left, lowerBound, root) and check(root->right, root, upperBound);
    }
    bool isValidBST(TreeNode *root)
    {
        return check(root, NULL, NULL);
    }
};