// Implementing two Stacks in an Array

#include <iostream>
using namespace std;

// Filling up the array from both ends -> Time Complexity - O(1), Space Complexity - O(1) for Four Operations
class twoStacks {
    int *arr;
    int top1,top2;
    int size;
    int n = 100;

    public:
    twoStacks(){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top1+1==top2 || top1==size-1 || top2==0){
            return;
        }
        top1++;
        arr[top1]=x;    
    }

    void push2(int x){
        if(top1+1==top2 || top1==size-1 || top2==0){
            return;
        }
        top2--;
        arr[top2] = x;
    }

    int pop1(){
        if(top1==-1){
            return -1;
        }
        int ele = arr[top1];
        top1--;
        return ele;
    }

    int pop2(){
        if(top2==size){
            return -1;
        }
        int ele = arr[top2];
        top2++;
        return ele;
    }

};


// Main Function
int main(){

    twoStacks ts;

    int Q;
    cin >> Q;
    while(Q--){
        int stackNo;
        cin >> stackNo;

        int queryType=0;
        cin >> queryType;

        if(queryType == 1){
            int a;
            cin >> a;

            if(stackNo == 1)
                ts.push1(a);
            else ts.push2(a);
        }else{
            if(stackNo == 1)
                cout << ts.pop1() << " ";
            else cout << ts.pop2() << " ";
        }
    }cout << "\n";

    return 0;
}