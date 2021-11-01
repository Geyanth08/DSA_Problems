// Rotate Doubly Linked List by N nodes

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
void displayNode(Node* &head);
void rotateNodes(Node* &head, int n);

// Main Function
int main(){
    Node* head = NULL;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);

    int n;
    cin >> n;

    displayNode(head); // 1 <--> 2 <--> 3 <--> 4 <--> 5 <--> 6 <--> NULL
    rotateNodes(head,n); // if n = 2
    displayNode(head); // 3 <--> 4 <--> 5 <--> 6 <--> 1 <--> 2 <--> NULL
    
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

// Using Simple Traversal -> Time Complexity - O(n), Space Complexity - O(1)
void rotateNodes(Node* &head,int n){

    if(n == 0) return;

    Node *curr = head;

    while(n--) curr = curr->next;
    Node* temp = curr->prev;
    temp->next = NULL;
    Node* newHead = curr;
    curr->prev = NULL;

    while(curr->next != NULL) curr = curr->next;
    curr->next = head;
    head->prev = curr;
    head = newHead;

}