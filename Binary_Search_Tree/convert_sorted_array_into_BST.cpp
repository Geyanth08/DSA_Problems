// Leetcode link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

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

// Using Binary Search -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    TreeNode *buildTree(vector<int> &nums, int low, int high)
    {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildTree(nums, low, mid - 1);
        root->right = buildTree(nums, mid + 1, high);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = buildTree(nums, 0, nums.size() - 1);

        return root;
    }
};