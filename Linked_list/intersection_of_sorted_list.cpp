// Intersection of Two Sorted Linked List

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
Node* findIntersection(Node* head1, Node* head2);

// Main Function
int main(){

    Node* firstList = NULL;
    Node* secondList = NULL;

    // First List
    insertNode(firstList,1);
    insertNode(firstList,2);
    insertNode(firstList,3);
    insertNode(firstList,4);
    insertNode(firstList,6);

    // Second List
    insertNode(secondList,2);
    insertNode(secondList,4);
    insertNode(secondList,6);
    insertNode(secondList,8);

    display(firstList);
    display(secondList);

    Node *head = findIntersection(firstList,secondList);
    display(head);

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
    }cout << "NULL" << "\n";
}

// By Simple Traversal - Time Complexity - O(M+N), Space Complexity - O(1)
Node* findIntersection(Node* head1, Node* head2){

    Node *head = NULL;
    Node *temp = head;
    while(head1 != NULL and head2 != NULL){
        if(head1->data == head2->data){
            Node *newNode = new Node(head1->data);
            if(head == NULL){
                head = newNode;
                temp = head;
            }else{
                temp->next = newNode;
                temp = temp->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }else if(head1->data > head2->data){
            head2 = head2->next;
        }else{
            head1 = head1->next;
        }
    }
    
    return head;
}