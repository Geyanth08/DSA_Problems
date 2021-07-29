// Reverse a String in Different Ways

#include <bits/stdc++.h>
using namespace std;

// Functions Declarations
void reverse_swap(string &str);
void reverse_reverse(string &str);
void reverse_for(string str);


// Main Function
int main(){
    string str;
    cin >> str;

    reverse_swap(str);
    cout << str << endl;
    return 0;
}

// Using inbuilt swap function
void reverse_swap(string &str){
    int n = str.length();

    for(int i=0;i<n/2;i++){
        swap(str[i],str[n-i-1]);
    }
}

// Using inbuit reverse function
void reverse_reverse(string &str){

    reverse(str.begin(),str.end());
}

// Using for loop
void reverse_for(string str){

    for(int i=str.length()-1;i>=0;i--){
        cout << str[i];
    }

}

