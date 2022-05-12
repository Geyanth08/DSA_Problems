// Leetcode link - https://leetcode.com/problems/intersection-of-two-linked-lists/
// Intersection Point in Y Shapped Linked List

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
void display(Node* &head);
void attachList(Node* &head, Node* &com);
int intersectPoint(Node* head1, Node* head2);

// Main Function
int main(){

    Node* firstList = NULL;
    Node* secondList = NULL;
    Node* common = NULL;

    // First List
    insertNode(firstList,3);
    insertNode(firstList,6);
    insertNode(firstList,9);


    // Second List
    insertNode(secondList,10);
    insertNode(secondList,11);

    // Common List
    insertNode(common,15);
    insertNode(common,30);

    attachList(firstList,common);
    display(firstList); // 3->6->9->15->30->NULL
    attachList(secondList,common);
    display(secondList); // 10->11->15->30->NULL

    cout << intersectPoint(firstList,secondList);

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

// Combining Two Linked Lists
void attachList(Node* &head, Node* &com){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = com;
}

// Printing a Linked List
void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL" << "\n";
}

// Shifting temp nodes when we get NULL -> Time Complexity - O(M+N), Space Complexity - O(1)
int intersectPoint(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return 0;
    
    Node *temp1 = head1;
    Node *temp2 = head2;
    
    while(temp1 != temp2){
        temp1 = temp1 == NULL ? head2 : temp1->next;
        temp2 = temp2 == NULL ? head1 : temp2->next;
    }
    
    return temp1->data;
}