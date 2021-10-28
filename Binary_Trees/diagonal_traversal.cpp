// Diagonal Traversal of Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Creating Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

// Function Declaration
void diagonal_traversal(TreeNode* root);

// Main Function
int main(){

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

    diagonal_traversal(root); // 1 3 6 | 2 5 | 4

    return 0;
}

// Using Hashmap and distance - Time Complexity - O(n), Space Complexity - O(n)
void diagonal_traversal(TreeNode* root){
    if(root == NULL) return;

    map<int,vector<int>> m;
    queue<pair<TreeNode* ,int>> q;

    q.push({root,0});

    int max_dd = 0;

    while(!q.empty()){
        TreeNode* curr = q.front().first;
        int dd = q.front().second;
        max_dd = max(max_dd,dd);

        q.pop();
        m[dd].push_back(curr->data);

        if(curr->left != NULL) q.push({curr->left,dd+1});
        if(curr->right != NULL) q.push({curr->right,dd});
    }

    for(int distance=0;distance<=max_dd;distance++){
        for(auto i : m[distance]){
            cout << i << " ";
        }
        cout << "\n";
    }
}