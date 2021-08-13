// Largest sum contiguous Subarray

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int largest_sum1(int arr[],int n);
int largest_sum2(int arr[],int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << largest_sum1(arr,n) << endl;

    return 0;
}

// Using Kadane's Algorithm -> Time Complexity - O(n), Space Complexity - O(1)
int largest_sum1(int arr[],int n){
    
    int curr_max = 0, max_so_far = INT_MIN;

    for(int i=0;i<n;i++){
        curr_max += arr[i];

        if(curr_max > max_so_far){
            max_so_far = curr_max;
        }

        if(curr_max < 0){
            curr_max = 0;
        }
    }

    return max_so_far;
}

// Another Approach -> Time Comlexity - O(n), Space Complexity - O(1)
int largest_sum2(int arr[],int n){
    int curr_max = 0, max_so_far = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i] <= curr_max + arr[i]){
            curr_max += arr[i];
        }else{
            curr_max = arr[i];
        }

        if(curr_max > max_so_far){
            max_so_far = curr_max;
        }
    }

    return max_so_far;
}