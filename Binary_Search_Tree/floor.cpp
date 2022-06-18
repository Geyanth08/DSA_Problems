// Practice link - https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457
// Find the greatest value node of the BST which is smaller than or equal to ‘X’.

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
int floorInBST(TreeNode *root, int X)
{
    int floor = -1;
    while (root)
    {
        if (root->val == X)
        {
            return root->val;
        }
        if (root->val > X)
            root = root->left;
        else
        {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}