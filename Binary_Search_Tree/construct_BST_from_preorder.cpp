// Leetcode link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

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

// Left nodes of root are less than root, Right nodes of root are greater in BST -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() or preorder[i] > bound)
            return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};