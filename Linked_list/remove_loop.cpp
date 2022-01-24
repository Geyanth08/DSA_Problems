// Remove Loop in Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node {
    int data;
    struct Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// Function Declaration
void insertNode(Node* &head, int val);
void loopHere(Node * head, int pos);
void removeLoop(Node* head);
bool detectLoop(Node* head);

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

    removeLoop(head);

    if(detectLoop(head)){
        cout << "Loop is Present";
    }else{
        cout << "No Loop";
    }

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
void removeLoop(Node* head){

    Node* low = head;
    Node* high = head;
    
    while(low != NULL and high != NULL and high->next != NULL){
        low = low->next;
        high = high->next->next;
        
        if(low == high) break;
    }
    
    if(low == head){
        while(high->next != low) high = high->next;
        high->next = NULL;
    }else if(low == high){
        low = head;
        while(low->next != high->next){
            low = low->next;
            high = high->next;
        }
        
        high->next = NULL;
    }
}

// Detect Loop (For Testing)
bool detectLoop(Node* head){

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