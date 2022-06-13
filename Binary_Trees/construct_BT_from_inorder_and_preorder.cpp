// Leetcode link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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

// Start of Preorder is root -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    TreeNode *build(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> inMap)
    {
        if (preStart > preEnd or inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(pre[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(pre, preStart + 1, preStart + numsLeft, in, inStart, inRoot - 1, inMap);
        root->right = build(pre, preStart + numsLeft + 1, preEnd, in, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

        return root;
    }
};