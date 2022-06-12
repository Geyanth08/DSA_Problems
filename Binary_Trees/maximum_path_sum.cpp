// Leetcode link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

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

// Using the concept of height and width of tree -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    int pathSum(TreeNode *root, int &maxSum)
    {
        if (root == NULL)
            return 0;
        int left = max(0, pathSum(root->left, maxSum));
        int right = max(0, pathSum(root->right, maxSum));

        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum;
    }
};