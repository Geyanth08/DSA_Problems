// Find Duplicant Characters in String

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
void duplicants1(string s);

// Main Function
int main(){
    string s;
    cin >> s;

    duplicants(s);

    return 0;
}

// Using Maps -> Time Complexity - O(nlogn), Space Complexity - O(size_of_map)
void duplicants(string s){

    map<char,int> mp;

    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }

    map<char,int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(it.second > 1){
            cout << it->first << " " << it->second << endl;
        }        
    }
}