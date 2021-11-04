// Evaluation of Postfix Expression

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int evaluatePostfix(string S);

// Main Function
int main(){
    string str;
    cin >> str;

    int result = evaluatePostfix(str);
    cout << result << "\n";

    return 0;
}

// Using push and pop operations -> Time Complexity - O(n), Space Complexit - O(1)
int evaluatePostfix(string S){

    stack<int> val;
    int op1,op2;
    
    for(int i=0;i<S.length();i++){
        if(S[i]>='0' and S[i]<='9'){
            val.push(S[i]-'0');
        }else{
            op1 = val.top();
            val.pop();
            
            op2 = val.top();
            val.pop();
            
            int res;
            switch(S[i]){
                case '+' : res = op2 + op1; break;
                case '-' : res = op2 - op1; break;
                case '*' : res = op2 * op1; break;
                case '/' : res = op2 / op1; break;
            }
            
            val.push(res);
        }
    }
    
    return val.top();
}