// Check Whether the given tree is balanced or not

#include <bits/stdc++.h>
using namespace std;

// Creating a Node in Binary Tree
struct Node {
    int data;
    struct Node *left, *right;

    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function Declaration
int heightOfTree(Node *root);
bool isBalanced(Node *root);

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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    if(isBalanced(root)){
        cout << "Tree is Balanced";
    }else{
        cout << "Tree is not Balanced";
    }

    return 0;
}

// Finding Height of Tree
int heightOfTree(Node *root){
    if(root == NULL) return 0;
    
    int lh = heightOfTree(root->left);
    if(lh == -1) return -1;
    int rh = heightOfTree(root->right);
    if(rh == -1) return -1;
    
    if(abs(lh - rh) > 1) return -1;
    return max(lh,rh)+1;
}

// Using Height of Tree -> Time Complexity - O(n), Space Complexity - O(1)   
bool isBalanced(Node *root){
    return heightOfTree(root) != -1;
}