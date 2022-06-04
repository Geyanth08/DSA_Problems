// Leetcode link - https://leetcode.com/problems/implement-stack-using-queues/
// Stack Using Two Queues

#include <bits/stdc++.h>
using namespace std;

// Using two Queues (PUSH operation costlier) -> Time Complexity - O(n) for push and O(1) for pop, Space Complexity - O(1)
class QueueStack1 {
    private :
        queue<int> q1;
        queue<int> q2;

    public :
        void push1(int val){

            while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
            }
            
            q1.push(val);
            
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

        int pop1(){

            int top_element;     
        
            if(q1.empty()) top_element = -1;
            else{
                top_element = q1.front();
                q1.pop();
            }
            
            return top_element;
        }
};

// Using two Queues (POP operation costlier) -> Time Complexity - O(1) for push and O(n) for pop, Space Complexity - O(1)
class QueueStack2 {
    private :
        queue<int> q1;
        queue<int> q2;

    public :
        void push2(int val){
            q1.push(val);           
        }

        int pop2(){
            int top_element;

            if(q1.empty()) top_element = -1;
            else{
                while(q1.size() != 1){
                    q2.push(q1.front());
                    q1.pop();
                }
                
                top_element = q1.front();
                q1.pop();
                
                while(!q2.empty()){
                    q1.push(q2.front());
                    q2.pop();
                }
            }

            return top_element;
        }
};

// Main Function
int main(){

    QueueStack2 qs;

    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            int val;
            cin >> val;
            qs.push2(val);
        }else {
            cout << qs.pop2() << " ";
        }
    }cout << "\n";

    return 0;
}
