// Check whether the given list is Circular Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// Function Declaration
void insertNode(Node* &head, int val);
void display(Node* &head);
void makeLinkAtEnd(Node *&head);
bool isCircular(Node *head);

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

    makeLinkAtEnd(head);

    cout << isCircular(head);

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

// Make a Link at End to change the list to circular
void makeLinkAtEnd(Node* &head){
    if(head == NULL) return;

    Node *temp = head;

    while(temp->next != NULL) temp = temp->next;

    temp->next = head;
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

// Simple Traversal -> Time Complexity - O(n), Space Complexity - O(1)
bool isCircular(Node *head){

   if(head == NULL) return true;
   
   Node *p = head->next;
   while(p != head and p != NULL){
       p = p->next;
   }
   
   return (p == head);
}