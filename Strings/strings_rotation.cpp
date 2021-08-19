// Check whether strings are rotation of each other

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool isRotate1(string s1, string s2);
bool isRotate2(string s1, string s2);

// Main Function
int main(){

    string s1,s2;
    cin >> s1 >> s2;

    if(isRotate2(s1,s2)){
        cout << "strings are rotations of each other";
    }else {
        cout << "strings are not rotations of each other";
    }

    return 0;
}

// Simple approach -> Time Complexity - O(s1+s2), Space Complexity - O(s1+s2)
bool isRotate1(string s1, string s2){
    
    if(s1.length() != s2.length())
        return false;

    string temp = s1 + s1;
    return (temp.find(s2));

}

// Using Queue
bool isRotate2(string s1, string s2){
    if(s1.length() != s2.length())
        return false;

    queue<char> q1;
    for(int i=0;i<s1.size();i++){
        q1.push(s1[i]);
    }

    queue<char> q2;
    for(int i=0;i<s2.size();i++){
        q2.push(s2[i]);
    }

    int length_of_s2 = s2.size();
    while(length_of_s2--){
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if(q2 == q1)
            return true;
    }
    return false;
}