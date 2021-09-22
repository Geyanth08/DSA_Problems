// Add Two Numbers represented by Linked List

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
Node* addTwoLists(struct Node* first, struct Node* second);

// Main Function
int main(){

    Node* firstNumber = NULL;
    Node* secondNumber = NULL;

    // First Number
    insertNode(firstNumber,9);
    insertNode(firstNumber,6);
    insertNode(firstNumber,9);

    // Second Number
    insertNode(secondNumber,8);
    insertNode(secondNumber,9);
    insertNode(secondNumber,1);

    display(firstNumber);
    cout << " ";
    display(secondNumber);
    cout << "\n";

    Node *add = addTwoLists(firstNumber,secondNumber);
    display(add);

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

// Adding nodes and carry -> Time Complexity - O(N+M), Space Complexity - O(max(N,M))
Node* addTwoLists(struct Node* first, struct Node* second){

    first = reverseList(first);
    second = reverseList(second);
    
    Node *head = new Node(0);
    Node *temp = head;
    
    int sum=0,carry=0;
    
    while(first != NULL || second != NULL || carry){
        sum = 0;
        if(first != NULL){
            sum += first->data;
            first = first->next;
        }
        
        if(second != NULL){
            sum += second->data;
            second = second->next;
        }
        
        sum += carry;
        carry = sum/10;
        Node *newNode = new Node(sum%10);
        temp->next = newNode;
        temp = temp->next;
    }
    
    head = reverseList(head->next);
    return head;
}