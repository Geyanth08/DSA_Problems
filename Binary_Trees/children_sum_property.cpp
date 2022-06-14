// Practice link - https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
// A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).
// Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

#include <bits/stdc++.h>
using namespace std;

// create a Node
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// increase child values, while backtracking increase root values -> Time Complexity - O(N), Space Complexity - O(N)
void changeTree(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    int child = 0;

    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    // Do not Update for Leaf nodes.
    if (root->left or root->right)
        root->data = tot;
}