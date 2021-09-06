// Common Operations on Stacks (Using Arrays)

#include <bits/stdc++.h>

#define n 100

// Implementation of Stack using Arrays -> Time Complexity - O(n)
class stack{

    int *arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top==n-1){
            std::cout << "Stack Overflow";
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop(){
        if(top==-1){
            std::cout << "No Elemnts in the stack to pop";
            return;
        }

        top--;
    }

    int Top(){
        if(top==-1){
            std::cout << "No Elemnts in the stack to pop";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

};

// Main Function
int main(){

    stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << s.Top() << "\n";

    s.pop();

    std::cout << s.Top() << "\n";

    if(s.isEmpty()){
        std::cout << "Stack is Empty" << "\n";
    }else{
        std::cout << "Stack Contains Elements" << "\n";
    }

    return 0;
}