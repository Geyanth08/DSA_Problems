// Remove Duplicates in sorted list

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
Node *removeDuplicates(Node *head);

// Main Function
int main(){

    Node *head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,2);
    insertNode(head,4);
    insertNode(head,6);
    insertNode(head,6);

    display(head); //1->2->2->4->6->6->NULL
    head = removeDuplicates(head);
    display(head); //1->2->4->6->NULL

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

// By Comparing Adjacent Elemnets - Time Complexity - O(n), Space Complexity - O(1)
Node *removeDuplicates(Node *head){
 
    Node *temp = head;
    if(!temp) return NULL;
    
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }else{
            temp = temp->next;
        }
    }
    
    return head;
}