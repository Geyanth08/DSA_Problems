// Leetcode link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Inorder Traversal of Binary Tree using Recursion and Iterative
// Inorder -> LEFT ROOT RIGHT

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
void recursive_inorder(Node *root);

void iterative_inorder(Node *root);

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

    // Inorder : 4 2 5 1 3 6
    iterative_inorder(root);
    recursive_inorder(root);

    return 0;
}

// Using Recursion -> Time Complexity - O(n), Space Complexity - O(n)
void recursive_inorder(Node *root){
    if(root == NULL){
        return;
    }

    recursive_inorder(root->left);

    cout << root->data << " ";

    recursive_inorder(root->right);
}

// Using Stacks (Iterative Approach) -> Time Complexity - O(n), Space Complexity - O(n)
void iterative_inorder(Node *root){
    
    stack<Node *> st;
    Node *curr = root;

    while(!st.empty() or curr != NULL){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }else{
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    cout << "\n";
}