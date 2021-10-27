// Reverse a Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

// Function Declaration
void insertNode(Node* &head,int val);
Node* reverseDLL(Node* &head);
void displayNode(Node* &head);

// Main Function
int main(){
    Node* head = NULL;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);

    displayNode(head);
    head = reverseDLL(head);
    displayNode(head);
    
    return 0;
}

// Inserting Nodes
void insertNode(Node* &head,int val){

    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Displaying Nodes
void displayNode(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " <--> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Using Simple Traversal - Time Complexity - O(n), Space Complexity - O(1)
Node* reverseDLL(Node* &head){

    if(head == NULL or head->next == NULL) return head;
    
    Node* temp = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        curr = curr->prev;
    }
    
    head = temp->prev;
    return head;
}
