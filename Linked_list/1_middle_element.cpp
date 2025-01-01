// Leetcode link - https://leetcode.com/problems/middle-of-the-linked-list/
// Middle of Linked List

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
Node* middleNode(Node* head);

// Main Function
int main(){
    
    Node* head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    // insertNode(head,6);

    display(head);  // 1->2->3->4->5->6->NULL
    head = middleNode(head);
    display(head);  // 4->5->6->NULL;
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

// Using fast and slow pointer -> Time Complexity - O(n), Space Complexity - O(n)
Node* middleNode(Node* head){
        
    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}