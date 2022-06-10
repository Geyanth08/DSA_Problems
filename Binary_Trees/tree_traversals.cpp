// Practice link - https://www.codingninjas.com/codestudio/problems/981269
// find the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

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

// Using Stack -> Time Complexity - O(N), Space Complexity - O(N)
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> allTraversal;
    if (root == NULL)
        return allTraversal;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    vector<int> pre, in, pos;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else
        {
            pos.push_back(it.first->data);
        }
    }

    allTraversal.push_back(in);
    allTraversal.push_back(pre);
    allTraversal.push_back(pos);

    return allTraversal;
}

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

    vector<vector<int>> traversals;
    traversals = getTreeTraversal(root);

    for (int i = 0; i < traversals.size(); i++)
    {
        for (int j = 0; j < traversals[0].size(); j++)
        {
            cout << traversals[i][j] << " ";
        }
        cout << "\n";
    }

    // Output:
    /*
        inorder: 4 2 5 1 3 6
        preorder: 1 2 4 5 3 6
        postorder: 4 5 2 6 3 1
    */

    return 0;
}