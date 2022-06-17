// Leetcode link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

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

// Compare root value with p and q then move either left or right -> Time Complexity - O(H), Space Complexity - O(H)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        int curVal = root->val;

        if (curVal < p->val and curVal < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (curVal > p->val and curVal > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};