// Reverse a String using Stack

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
char* reverse(char *S, int len);

// Main Function
int main(){

    char str[100];
    cin >> str;

    int len = strlen(str);
    char *ch = reverse(str,len);

    for(int i=0;i<len;i++){
        cout << ch[i];
    }cout << "\n";

    return 0;
}

// Push and Pop -> Time Complexity - O(n), Space Complexity - O(n)
char* reverse(char *S, int len){

    stack<char> reverse_string;
    
    for(int i=0;i<len;i++){
        reverse_string.push(S[i]);
    }
    
    for(int i=0;i<len;i++){
        S[i] = reverse_string.top();
        reverse_string.pop();
    }
    
    return S;
}