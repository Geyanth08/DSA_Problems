// Leetcode link - https://leetcode.com/problems/two-sum/
// Count the pairs with given sum

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int getPairsCount(int arr[], int n, int k);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << getPairsCount(arr,n,k) << "\n";
    return 0;
}

// Using maps (storing frequency) -> Time Complexity - O(n), Space Complexity - O(n)
int getPairsCount(int arr[], int n, int k){
    map<int,int> m;
    int count = 0;
    for(int i=0;i<n;i++){
        if(m.find(k-arr[i]) != m.end()){
            count += m[k-arr[i]];
        }
        m[arr[i]]++;
    }
    
    return count;
}