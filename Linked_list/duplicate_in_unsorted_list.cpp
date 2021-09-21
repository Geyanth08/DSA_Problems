// Remove Duplicates in Unsorted List

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
Node * removeDuplicates( Node *head);

// Main Function
int main(){

    Node *head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,6);
    insertNode(head,2);
    insertNode(head,4);
    insertNode(head,6);
    insertNode(head,4);

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

// Using maps - Time Complixity - O(n), Space Complexity - O(n)
Node * removeDuplicates( Node *head) {

    Node *curr = head->next;
    Node *prev = head;
    
    map<int,int> m;
    m[prev->data] = 1;
    
    while(curr != NULL){
        if(m.find(curr->data) == m.end()){
            m[curr->data] = 1;
            prev = curr;
        }else{
            prev->next = curr->next;
            free(curr);
        }
        curr = prev->next;
    }
    
    return head;
}