// Practice link - https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725
// Print the boundary nodes of this binary tree in Anti-Clockwise direction starting from the root node.

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

// Function Declaration
bool isLeaf(TreeNode *node);
void addLeftBoundary(TreeNode *root, vector<int> &res);
void addRightBoundary(TreeNode *root, vector<int> &res);
void addLeaves(TreeNode *root, vector<int> &res);
vector<int> traverseBoundary(TreeNode *root);

// Main Function
int main()
{

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    // Creating above Binary Tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> boundary;
    boundary = traverseBoundary(root);

    for (int i = 0; i < boundary.size(); i++)
    {
        cout << boundary[i] << " ";
    }
    cout << "\n";
}

// Combine left Boundary nodes and leaf nodes and Right Boundary nodes -> Time Complexity - O(N), Space Complexity - O(N)
vector<int> traverseBoundary(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

bool isLeaf(TreeNode *node)
{
    return !node->left and !node->right;
}

void addLeftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *cur = root->right;
    stack<int> s;
    while (cur)
    {
        if (!isLeaf(cur))
            s.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
}

// Using Inorder Traversal
void addLeaves(TreeNode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}
