// Leetcode link - https://leetcode.com/problems/reverse-linked-list/
//Reverse the given Linked List

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
Node* reverse_iterative(Node* &head);
void display(Node* &head);
Node* reverse_recursive(Node* &head);

// Main Function
int main(){

    Node* head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);

    display(head);  // 1->2->3->4->5->NULL
    head = reverse_recursive(head);
    display(head);  // 5->4->3->2->1->NULL
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

// Time Complexity -> O(n)  ,Space Complexity -> O(1)
Node* reverse_iterative(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

// Time Complexity -> O(n)  ,Space Complexity -> O(1)
Node* reverse_recursive(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
