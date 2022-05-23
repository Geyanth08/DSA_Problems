// Leetcode link - https://leetcode.com/problems/binary-tree-preorder-traversal/
// Preorder Traversal of Binary Tree using Recursion and Iterative
// Preorder -> ROOT LEFT RIGHT

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
void recursive_preorder(Node *root);
void iterative_preorder(Node *root);

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

    // Preorder : 1 2 4 5 3 6
    recursive_preorder(root);
    cout << "\n";
    iterative_preorder(root);

    return 0;
}

// Using Recursion -> Time Complexity - O(n), Space Complexity - O(n)
void recursive_preorder(Node *root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    recursive_preorder(root->left);
    recursive_preorder(root->right);

}

// Using Stacks (Iterative Approach) -> Time Complexity - O(n), Space Complexity - O(n)
void iterative_preorder(Node *root){

    if(root == NULL){
        return;
    }

    stack<Node *> st;
    st.push(root);

    while(!st.empty()){
        
        root = st.top();
        st.pop();

        cout << root->data << " ";

        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }

}