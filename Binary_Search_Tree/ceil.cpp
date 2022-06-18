// Practice link - https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464
// Find the closest value node of the BST which is greater than or equal to ‘X’

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

// Using Binary Search -> Time Complexity - O(H), Space Complexity - O(1)
int findCeil(TreeNode *node, int x)
{
    int ceil = -1;
    while (node)
    {
        if (node->val == x)
        {
            return node->val;
        }
        if (node->val < x)
        {
            node = node->right;
        }
        else
        {
            ceil = node->val;
            node = node->left;
        }
    }

    return ceil;
}