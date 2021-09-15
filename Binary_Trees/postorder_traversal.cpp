// Postorder Traversal of Binary Tree using Recursion and Iterative
// Postorder -> LEFT RIGHT ROOT

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
void recursive_postorder(Node *root);
void iterative_postorder1(Node *root);

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

    // Postorder : 4 5 2 6 3 1
    recursive_postorder(root);
    cout << "\n";
    iterative_postorder1(root);

    return 0;
}

// Using Recursion -> Time Complexity - O(n), Space Complexity - O(n)
void recursive_postorder(Node *root){
    if(root == NULL){
        return;
    }

    recursive_postorder(root->left);
    recursive_postorder(root->right);

    cout << root->data << " ";
}

// Using 2 Stacks -> Time Complexity - O(n), Space Complexity - O(2n)
void iterative_postorder1(Node *root){

    if(root == NULL) return;

    stack<Node *> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left != NULL){
            st1.push(root->left);
        }
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
}