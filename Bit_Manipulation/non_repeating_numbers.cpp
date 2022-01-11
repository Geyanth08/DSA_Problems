// Find two non repeating numbers from an array containing 2*N + 2 Numbers

#include <bits/stdc++.h>
using namespace std;

// Function declaration
vector<int> singleNumber(vector<int> &nums);

// Main Function
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    vector<int> ans;
    ans = singleNumber(arr);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

}

// Using xor and 2s complement (set bit) -> Time Complexity - O(n), Space Complexity - O(1)
vector<int> singleNumber(vector<int>& nums) {

    int xor_all=0;
    for(int i=0;i<nums.size();i++){
        xor_all ^= nums[i];
    }
    
    int right_most = xor_all & (~(xor_all - 1));
    int x=0,y=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]&right_most){
            x ^= nums[i];
        }else{
            y ^= nums[i];
        }
    }
    
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin(),ans.end());
    
    return ans;
}