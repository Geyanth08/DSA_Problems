// Find Pairs with given sum in Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

// Function Declaration
void display(Node* &head);
void insertNode(Node* &head,int val);
void pairSum(Node* head,int sum);

// Main Function
int main(){
    Node* head = NULL;

    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,7);

    int target;
    cin >> target;

    pairSum(head,target);

    return 0;
}

// Inserting a Node
void insertNode(Node* &head, int val){
    
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Displaying List
void display(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " <--> ";
        temp = temp->next;
    }

    cout << "NULL" << "\n";
}

// Using Two Pointers -> Time Complexity - O(n), Space Complexity - O(1)
void pairSum(Node* head,int sum){

    Node* first = head;
    Node* last = head;
    while(last->next != NULL) last = last->next;

    bool found = false;

    while((first != last) and (first != last->next)){
        if((first->data + last->data) == sum){
            found = true;

            cout << "(" << first->data << ", " << last->data << ") ";
            first = first->next;
            last = last->prev; 
        }else{
            if((first->data + last->data) < sum) first = first->next;
            else last = last->prev;
        }
    }

    if(!found) cout << " No pairs Found" << "\n";
}