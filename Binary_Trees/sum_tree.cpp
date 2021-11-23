//  Transform Binary Tree to Sum Tree

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
int solve(Node *root);
void recursive_inorder(Node *root);

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

    solve(root);
    recursive_inorder(root);

    return 0;
}

// Using Recursion (Add left, right,curr node values and return) -> Time Complexity - O(n), Space Complexity - O(Height of Tree)
int solve(Node *root){

    if(!root) return 0;
    
    int left = solve(root->left);
    int right = solve(root->right);
    
    int curr = root->data;
    root->data = left + right;
    
    return left + right + curr;
}

// printing Binary Tree : Inorder
void recursive_inorder(Node *root){
    if(root == NULL){
        return;
    }

    recursive_inorder(root->left);

    cout << root->data << " ";

    recursive_inorder(root->right);
}