// Expression contians redundant bracket or Not

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool checkRedundant(string S);

// Main Function
int main(){

    string str;
    cin >> str;

    bool check = checkRedundant(str);
    if(check) cout << "Expression contains redundant brackets" << endl;
    else cout << "Expression does not contains any redundant brackets" << endl;

    return 0;
}

// checking when we get ')' -> Time Complexity - O(n), Space Complexity - O(1)
bool checkRedundant(string S){
    stack<char> expst;

    for(int i=0;i<S.size();i++){
        if(S[i]=='+' or S[i]=='-' or S[i]=='*' or S[i]=='/' or S[i]=='('){
            expst.push(S[i]);
        }else if(S[i]==')'){
            if(expst.top() == '(') return true;
            if(expst.top() == '+' or expst.top() == '*' or expst.top() == '-' or expst.top() == '/'){
                expst.pop();
            }
            expst.pop();
        }
    }

    return false;
}
