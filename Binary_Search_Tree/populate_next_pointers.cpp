// Leetcode link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node
{
    int data;
    Node *left, *right, *next;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Using Level Order Traversal -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (i != n - 1)
                {
                    temp->next = q.front();
                }

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return root;
    }
};