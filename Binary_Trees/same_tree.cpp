// Leetcode link - https://leetcode.com/problems/same-tree/
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

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

// check whether the traversal of both trees are same -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL or q == NULL)
            return (p == q);
        return (p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};