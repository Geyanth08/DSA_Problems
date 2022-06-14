// Leetcode link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Given the root of a binary tree, flatten the tree into a "linked list":

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

// Using stack -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root == NULL)
            return;

        st.push(root);
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);

            if (!st.empty())
                curr->right = st.top();
            curr->left = NULL;
        }
    }
};