// Leetcode link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Calculate the vertical order traversal of the binary tree.

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

// Using Level Order Traversal -> Time Complexity - O(N*logN*logN*logN), Space Complexity - O(N)
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}}); // (node,vertical level,level)
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            TreeNode *node = curr.first;
            int x = curr.second.first, y = curr.second.second;

            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto it1 : nodes)
        {
            vector<int> col;
            for (auto it2 : it1.second)
            {
                col.insert(col.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};