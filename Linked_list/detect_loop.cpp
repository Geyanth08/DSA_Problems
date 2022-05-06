// Leetcode link - https://leetcode.com/problems/linked-list-cycle/
// Detect Loop in a Linked List

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
void loopHere(Node * head, int pos);
bool detectLoop1(Node* head);
bool detectLoop2(Node* head);

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

    int pos;
    cin >> pos;
    loopHere(head,pos);

    cout << detectLoop2(head);

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

// Creating a loop
void loopHere(Node * head, int pos){
    if(pos == 0) return;

    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node *walk = head;
    for(int i=0;i<pos;i++){
        walk = walk->next;
    }
    tail->next = walk;
}

// By Modifying the value of Node - Time Complexity - O(n), Space Complexity - O(1)
bool detectLoop1(Node* head){

    Node *temp = head;
    if(temp == NULL || temp->next == NULL) return false;
    while(temp != NULL){
        if(temp->data < 0){
            return true;
        }
        temp->data *= -1;
        temp = temp->next;
    }
    return false;
}

// Using Floyds Cycle Detection Algorithm -> Time Complexity - O(n), Space Complexity - O(1)
bool detectLoop2(Node* head){

    if(head == NULL || head->next == NULL) return false;

    Node *fast = head;
    Node *slow = head;

    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}