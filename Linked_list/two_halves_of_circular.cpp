// Split a Circular Linked List into two halves

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
void splitList(Node* &head, Node* &head1_ref, Node* &head2_ref);

// Main Function
int main(){
    
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);

    makeLinkAtEnd(head);
    display(head); // Complete Circular List : 1->2->3->4->5->6->NULL
    splitList(head,head1,head2);

    display(head1); // First half : 1->2->3->NULL
    display(head2); // Second half : 4->5->6->NULL

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
    
    if(temp != NULL){
        do{
            cout << temp->data << "->";
            temp = temp->next;
        }while(temp != head);
    }

    cout << "NULL" << endl;
}

// Using Slow and Fast Pointer - Time Complexity - O(n), Space Complexity - O(1)
void splitList(Node *&head, Node *&head1_ref, Node *&head2_ref){

    if(head == NULL) return;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next != head and fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Even Nodes
    if(fast->next->next == head){
        fast = fast->next;
    }
    
    head1_ref = head;
    
    if(head->next != head){
        head2_ref = slow->next;
    }
    
    fast->next = slow->next;
    slow->next = head;
    
}