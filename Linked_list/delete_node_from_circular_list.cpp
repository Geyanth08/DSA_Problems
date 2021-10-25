// Deletion from a Circular Linked List 

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
void deleteNode(Node* &head,int target);

// Main Function
int main(){
    
    Node* head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
   
    makeLinkAtEnd(head);
    
    int target;
    cin >> target;

    deleteNode(head,target);
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

// Using Simple traversal -> Time Complexity - O(n), Space Complexity - O(1)
void deleteNode(Node* &head,int target){

    Node* temp = head;

    if(head == NULL) return;

    // When List has Single Node
    if(head->next == head and head->data == target) {
        free(temp);
        head = NULL;
        return;
    } 

    // When Head is to be Deleted
    if(head->data == target){
        while(temp->next != head) temp = temp->next;

        temp->next = head->next;
        free(head);
        head = temp->next;
    }

    while(temp->next != head and temp->next->data != target) temp = temp->next;

    if(temp->next->data == target){
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }else{
        cout << "Element Not Found" << "\n";
    }
}