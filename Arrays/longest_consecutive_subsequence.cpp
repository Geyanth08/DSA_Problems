// Leetcode link - https://leetcode.com/problems/longest-consecutive-sequence/
// Longest Consecutive Subsequence

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int longest_consecutive_subseq1(int arr[],int n);
int longest_consecutive_subseq2(int arr[],int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << longest_consecutive_subseq1(arr,n) << endl;
    return 0;
}

// sort and traverse -> Time Complexity - O(NlogN), Space Complexity - O(1)
int longest_consecutive_subseq1(int arr[],int n){
    int ans = 0, count = 0;

    sort(arr,arr+n);

    vector<int> v;
    v.push_back(arr[0]);

    for(int i=0;i<n;i++){
        if(arr[i] != arr[i-1]){
            v.push_back(arr[i]);
        }
    }

    for(int i=0;i<v.size();i++){
        if(i>0 && v[i] == v[i-1]+1){
            count++;
        }else{
            count = 1;
        }

        ans = max(ans,count);
    }

    return ans;
}

// Using Hashing (implemented by set) -> Time Complexity - O(n), Space Complexity - O(n)
int longest_consecutive_subseq2(int arr[],int n){
    set<int> hashset;
      
    for(int i=0;i<n;i++){
      hashset.insert(arr[i]);
    }
      
    int longestStreak = 0;
      
    for(int i=0;i<n;i++){
        if(!hashset.count(arr[i]-1)){
            int currNum = arr[i];
            int currStreak = 1;
              
            while(hashset.count(currNum+1)){
                currNum ++;
                currStreak++;
            }
              
            longestStreak = max(longestStreak,currStreak);
        }
    }
      
    return longestStreak;
}