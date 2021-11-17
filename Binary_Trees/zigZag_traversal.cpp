// Zig Zag Traversal of Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node {
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function Declaration
vector<int> zigZagTraversal(Node *root);

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

    // Zig Zag Order : 1 3 2 4 5 6 
    vector<int> zigZag_order = zigZagTraversal(root);

    for(int i=0;i<zigZag_order.size();i++){
        cout << zigZag_order[i] << " ";
    }cout << "\n";

    return 0;
}

// Using a Flag variable to change direction of traversal -> Time Complexity - O(n), Space Complexity - O(n)
vector <int> zigZagTraversal(Node* root){

    vector<int> zigZag;
    if(root == NULL) return zigZag;

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        
        for(int i=0;i<size;i++){
            Node *temp = q.front();
            q.pop();
            
            int index = leftToRight ? i : (size - 1 - i);
            row[index] = temp->data;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        leftToRight = !leftToRight;
        for(int i=0;i<size;i++){
            zigZag.push_back(row[i]);
        }
    }

    return zigZag;
}