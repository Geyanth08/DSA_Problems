// Leetcode link - https://leetcode.com/problems/reverse-nodes-in-k-group/
// Reverse every K Nodes in Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating a NODE
struct Node {
    int data;
    struct Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};


// Function Declaration
void insertNode(Node* &head, int val);
void display(Node* &head);
Node* reverse_k_nodes(Node* &head, int K);


// Main Function
int main(){

    Node* head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);

    display(head);  // 1->2->3->4->5->6->NULL
    head = reverse_k_nodes(head,2);
    display(head);  // 2->1->4->3->6->5->NULL

    return 0;
}

// Inserting a NewNode
void insertNode(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

// Printing a Linked List
void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Using Recurrsion - Time Complexity -> O(n), Space Complexity -> )(n/K)
Node* reverse_k_nodes(Node* &head, int K){
    if(head == NULL)
        return NULL;
    
    Node* currptr = head;
    Node* prevptr = NULL;
    Node* nextptr = NULL;

    int count = 0;

    while(currptr != NULL && count < K){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL){
        head->next = reverse_k_nodes(nextptr,K);
    }

    return prevptr;
}