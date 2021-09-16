// Reverse Level Order of a Binary Tree

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
vector<int> reverseLevelOrder(Node *root);

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

    // Reverse Levelorder : 4 5 6 2 3 1
    vector<int> order = reverseLevelOrder(root);
    for(int i=0;i<order.size();i++){
        cout << order[i] << " ";
    }

}

// Using Queue -> Time Complexity - O(n), Space Complexity - O(n)
vector<int> reverseLevelOrder(Node *root){

    vector<int> reverse_level_order;
    if(!root) return reverse_level_order;
    
    queue<Node*> q;
    q.push(root);
    
    
    while(!q.empty()){
        Node *temp = q.front();
        reverse_level_order.push_back(temp->data);
        
        if(temp->right != NULL) q.push(temp->right);
        if(temp->left != NULL) q.push(temp->left);
        
        q.pop();
    }
    
    reverse(reverse_level_order.begin(),reverse_level_order.end());
    
    return reverse_level_order;
}