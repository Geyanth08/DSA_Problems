// Leetcode link - https://leetcode.com/problems/binary-tree-level-order-traversal/
// Level Order Traversal of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Creating a Node in Binary Tree
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function Declaration
vector<int> levelOrder(Node *root);

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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Levelorder : 1 2 3 4 5 6
    vector<int> level_order = levelOrder(root);

    for (int i = 0; i < level_order.size(); i++)
    {
        cout << level_order[i] << " ";
    }
    cout << "\n";

    return 0;
}

// Using Queues -> Time Complexity - O(n), Space Complexity - O(n)
vector<int> levelOrder(Node *root)
{

    vector<int> arr;

    if (root == NULL)
        return arr;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            arr.push_back(node->data);
        }
    }

    return arr;
}