// Leetcode link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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

// End of Postorder is root -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    TreeNode *build(vector<int> &post, int postStart, int postEnd, vector<int> &in, int inStart, int inEnd, map<int, int> inMap)
    {
        if (postStart > postEnd or inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(post[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(post, postStart, postStart + numsLeft - 1, in, inStart, inRoot - 1, inMap);
        root->right = build(post, postStart + numsLeft, postEnd - 1, in, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

        return root;
    }
};