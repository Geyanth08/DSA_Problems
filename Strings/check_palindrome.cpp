// Check whether given string is Palindrome or not

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
string isPalidrome1(string s);
string isPalidrome2(string s);

// Main Function
int main(){

    string str;
    cin >> str;

    cout << isPalidrome2(str);

    return 0;
}

// Using reverse inbuilt function - Time Complexity -> O(n), Space Complexity -> O(n) : temp string 
string isPalidrome1(string s){

    string temp = s;

    reverse(temp.begin(),temp.end());

    if(s == temp){
        return "Yes";
    }
    return "No";
}

// Using for loop - Time Complexity -> O(n), Space Complexity -> O(1)
string isPalidrome2(string s){

    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            return "No";
        }
    }
    return "Yes";
}