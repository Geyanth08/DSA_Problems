// Leetcode link - https://leetcode.com/problems/symmetric-tree/
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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

// In symmetry left becomes right, right becomes left -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (left == NULL or right == NULL)
            return left == right;

        if (left->val != right->val)
            return false;

        return (symmetric(left->left, right->right)) and symmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL or symmetric(root->left, root->right))
            return true;
        return false;
    }
};