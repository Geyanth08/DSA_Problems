// Move Last Element to Front of a given Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating a NODE
struct Node {
    int data;
    struct Node* next;

    Node(int val){
        this->data = val;
        next = NULL;
    }
};

// Function Declaration
void insertNode(Node* &head, int val);
void display(Node* &head);
Node * moveLasttoFront(Node *head);

// Main Function
int main(){

    Node *head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);

    display(head); //1->2->3->4->5->6->NULL
    head = moveLasttoFront(head);
    display(head); //6->1->2->3->4->5->NULL

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

// Using Simple Traversal - Time Complexity - O(n), Space Complexity - O(1)
Node * moveLasttoFront(Node *head){
    Node *temp = head;
    // Node *secondLast = NULL;
    if(head == NULL or head->next == NULL) return head;

    while(temp->next->next != NULL){
        // secondLast = temp;
        temp = temp->next;
    }

    temp->next->next = head;
    head = temp->next;
    temp->next = NULL;

    return head;
}