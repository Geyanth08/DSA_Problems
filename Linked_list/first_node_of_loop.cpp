// Find First Node of Loop in Linked List

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
int firstNode(Node* head);

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

    cout << firstNode(head);

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

// Using Floyds Cycle Detection Algorithm -> Time Complexity - O(n), Space Complexity - O(1)
int firstNode(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) break;
    }

    if(slow == head) return head->data;
    else if(slow == fast){
        slow = head;

        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        return fast->next->data;
    }

    return 0;
}