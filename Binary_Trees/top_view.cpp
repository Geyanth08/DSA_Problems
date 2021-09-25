// Top View of Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Function Declaration
vector<int> topView(Node *root);

// Main Function
int main(){

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           /
          7
    */

    // Creating above Binary Tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);

    vector<int> view;
    view = topView(root); // 4 2 1 3 6
    for(int i=0;i<view.size();i++){
        cout << view[i] << " ";
    }cout << "\n";

}

// Using Vertical Traversal - Time Complexity - O(n), Space Complexity - O(n)
vector<int> topView(Node *root){
    vector<int> tView;
    if(root == NULL) return tView;

    queue<pair<Node*,int>> q;
    map<int,int> m;

    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node *temp = it.first;
        int line = it.second;

        if(m.find(line) == m.end()) m[line] = temp->data;

        if(temp->left != NULL) q.push({temp->left, line-1});
        if(temp->right != NULL) q.push({temp->right, line+1});
    }

    for(auto it : m){
        tView.push_back(it.second);
    }

    return tView;
}
