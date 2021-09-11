// Search an Element in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int search(vector<int>& nums, int target);

// Main Function
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;

    cout << search(arr,target) << endl;

    return 0;
}

// Using Binary Search -> Time Complexity - O(logn), Space Complexity -> O(1)
int search(vector<int>& nums, int target){
    int low=0,high=nums.size()-1,mid;
        
    while(low<=high){
        mid = (low+high)/2;
            
        if(nums[mid]==target){
            return mid;
        }

        // low to mid is sorted
        if(nums[low] <= nums[mid]){
            
            if(nums[low] <= target and nums[mid] >= target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        // mid to high is sorted
        }else{
            
            if(nums[mid] <= target and nums[high] >= target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
        
    return -1;
}