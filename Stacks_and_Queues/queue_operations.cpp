// Common Operations on Queues (using Arrays)

#include <iostream>
using namespace std;

#define n 100

class queue {
    int *arr;
    int front;
    int rear;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void push(int x){
        if(rear==n-1){
            cout << "Queue Overflow" << "\n";
            return;
        }

        rear++;
        arr[rear] = x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>rear){
            cout << "No Elements in Queue" << "\n";
            return;
        }

        front++;
    }

    int peek(){
        if(front==-1 || front>rear){
            cout << "No Elements in Queue" << "\n";
            return -1;
        }

        return arr[front];
    }

    bool isEmpty(){
        if(front==-1 || front>rear){
            return true;
        }
        return false;
    }
};


// Main Function
int main(){

    queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << "\n";

    q.pop();

    cout << q.peek() << "\n";

    q.pop();
    q.pop();
    q.pop();

    cout << q.isEmpty() << "\n";

    return 0;
}