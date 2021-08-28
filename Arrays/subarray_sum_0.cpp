// Find if there is a subarray sum with 0.

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool subArrayExists(int arr[], int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    if(subArrayExists(arr,n)){
        cout << "Found a Subarray with sum 0" << endl;
    }else{
        cout << "No Subarray is found with sum 0" << endl;
    }
    
    return 0;
}

// Using Hashing (implemented by Unordered_set) -> Time Complexity - O(n), Space Complexity - O(n)
bool subArrayExists(int arr[], int n){

    unordered_set<int> prevSum;
        
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
            
        if(sum ==0 || prevSum.find(sum) != prevSum.end()){
            return true;
        }
            
        prevSum.insert(sum);
    }
        
    return false;
}