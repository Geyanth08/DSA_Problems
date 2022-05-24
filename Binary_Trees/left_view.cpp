// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
// Left View of Binary Tree

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
void recursive_lView(Node *root,int level,vector<int> &lView);
vector<int> leftView(Node *root);

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
    view = leftView(root); // 1 2 4 7
    for(int i=0;i<view.size();i++){
        cout << view[i] << " ";
    }cout << "\n";

}

// To get Left view
void recursive_lView(Node *root,int level,vector<int> &lView){
    if(root == NULL) return;
    
    if(level == lView.size()) lView.push_back(root->data);
    
    recursive_lView(root->left,level+1,lView);
    recursive_lView(root->right,level+1,lView);
}

// Using Recursion -> Time Complexity - O(n), Space Complexity - O(heigth of tree)
vector<int> leftView(Node *root){

   vector<int> lView;
   recursive_lView(root,0,lView);
   return lView;
}