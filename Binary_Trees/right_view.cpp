// Leetcode link - https://leetcode.com/problems/binary-tree-right-side-view/
// Right View of Binary Tree

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
void recursive_rView(Node *root,int level,vector<int> &rView);
vector<int> rightView(Node *root);

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
    view = rightView(root); // 1 3 6 7
    for(int i=0;i<view.size();i++){
        cout << view[i] << " ";
    }cout << "\n";

}

// To get Right view
void recursive_rView(Node *root,int level,vector<int> &rView){
    if(root == NULL) return;
    
    if(level == rView.size()) rView.push_back(root->data);
    
    recursive_rView(root->right,level+1,rView);
    recursive_rView(root->left,level+1,rView);
}

// Using Recursion -> Time Complexity - O(n), Space Complexity - O(heigth of tree)
vector<int> rightView(Node *root){

   vector<int> rView;
   recursive_rView(root,0,rView);
   return rView;
}