// Power Set - All possible subsequences of the String in lexicographically-sorted array

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<string> AllPossibleStrings(string s);

// Main Function
int main(){

    string s;
    cin >> s;

    vector<string> subStrings;
    subStrings = AllPossibleStrings(s);

    for(auto it : subStrings){
        cout << it << " ";
    }

    return 0;
}

// Constructing Substrings through set bits -> Time Complexity - O(n*2^n), Space Complexity - O(1)
vector<string> AllPossibleStrings(string s){

    int n = s.size();
    vector<string> str;
    
    for(int num = 0;num< (1 << n);num++){
        string sub = "";
        for(int i=0;i<n;i++){
            if(num & (1<<i)){
                sub += s[i];
            }
        }
        
        if(sub.size() > 0){
            str.push_back(sub);
        }
    }
    
    sort(str.begin(),str.end());
    return str;
}