// Find th Duplicate (Only 1 number is repeated) in the Array containing N+1 elements having values between 1 to n

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int findDuplicate(vector<int> &arr);

// Main Function
int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << findDuplicate(arr);

    return 0;
}

// Using abs() function -> Time Complexity - O(n), Space Complexity - O(1)
int findDuplicate(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        int curr = abs(nums[i]);
        if(nums[curr] < 0){
          return curr;
        }
        nums[curr] *= -1;
    }
    return -1;
}