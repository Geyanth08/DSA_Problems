// Leetcode lnk - https://leetcode.com/problems/maximum-width-of-binary-tree/
// Given the root of a binary tree, return the maximum width of the given tree.

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

// Index nodes and perform Level Order Traversal -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int width = 0;
        queue<pair<TreeNode *, long long>> q;

        q.push({root, 0});
        while (!q.empty())
        {
            int n = q.size();
            long long minValue = q.front().second;
            long long first, last;

            for (int i = 0; i < n; i++)
            {
                long long curr_ind = q.front().second - minValue;
                TreeNode *node = q.front().first;

                q.pop();

                if (i == 0)
                    first = curr_ind;
                if (i == n - 1)
                    last = curr_ind;

                if (node->left)
                    q.push({node->left, curr_ind * 2 + 1});
                if (node->right)
                    q.push({node->right, curr_ind * 2 + 2});
            }

            width = max(width, int(last - first + 1));
        }

        return width;
    }
};