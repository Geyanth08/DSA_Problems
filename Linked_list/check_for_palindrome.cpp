// Check if Linked List is palindrome

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
bool isPalindrome(Node *head);
Node* reverse(Node* &head);
bool compare(Node* head1,Node* head2);

// Main Function
int main(){
    
    Node* head = NULL;

    // Adding Nodes
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,3);
    insertNode(head,2);
    insertNode(head,1);

    if(isPalindrome(head)){
        cout << "Linked list is a Palindrome";
    }else{
        cout << "Not a Palindrome";
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

// By getting Middle Element and reversing the second half and comparing -> Time Complexity - O(N), Space Complexity - O(1)
bool isPalindrome(Node *head){

    Node* slow = head;
    Node* fast = head;
    Node* second_half, *slow_prev = head;
    Node* middle = NULL;

    bool res = true;

    if(head != NULL and head->next != NULL){
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow_prev = slow;
            slow = slow->next;
        }
        
        if(fast != NULL){
            middle = slow;
            slow = slow->next;
        }
        
        second_half = slow;
        slow_prev->next = NULL;
        
        second_half = reverse(second_half);
        
        res = compare(head,second_half);
        
        second_half = reverse(second_half);
        
        if(middle != NULL){
            slow_prev->next = middle;
            middle->next = second_half;
        }else {
            slow_prev->next = second_half;
        }
    }

    return res;
}

// Reverse Linked List
Node* reverse(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}    

// Compare first half and second half of linked list 
bool compare(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1 and temp2){
        if(temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else{
            return 0;
        }
    }
    
    if(temp1 == NULL and temp2 == NULL) return 1;
    return 0;
}