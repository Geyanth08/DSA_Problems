// Leetcode link - https://leetcode.com/problems/binary-search-tree-iterator/
// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST)

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

// Using Inorder Traversal -> Time Complexity - O(1), Space Complexity - O(H)
class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        TreeNode *temp = root;
        for (; temp != NULL; st.push(temp), temp = temp->left)
            ;
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        TreeNode *tmp = temp->right;
        for (; tmp != NULL; st.push(tmp), tmp = tmp->left)
            ;

        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};