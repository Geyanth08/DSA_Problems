// Add 1 to a number represented as linked list

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
Node* reverseList(Node* head);
void display(Node* &head);
Node* addOne(Node *head);

// Main Function
int main(){

    Node* head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);

    display(head);  // 1->2->3->NULL
    cout << "\n";
    head = addOne(head);
    display(head);  // 1->2->4->NULL
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
        cout << temp->data;
        temp = temp->next;
    }
}

// Reversing the list
Node *reverseList(Node * head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// By reversing the list and adding 1 -> Time Complexity - O(n), Space Complexity -> O(1)
Node* addOne(Node *head){
    
    head = reverseList(head);
    
    bool flag=true;
    Node *curr = head;
    
    while(curr != NULL and flag){
        if(curr->next == NULL and curr->data == 9){
            curr->data = 1;
            Node *newNode = new Node(0);
            newNode->next = head;
            head = newNode;
        }else if(curr->data == 9){
            curr->data = 0;
        }else{
            curr->data = curr->data + 1;
            flag = false;
        }
        curr = curr->next;
    }
    
    head = reverseList(head);
    
    return head;
}