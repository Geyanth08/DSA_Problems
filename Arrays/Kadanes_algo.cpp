// Kadane's Algorithm

/*
    -> Intialize max_so_far = INT_MIN and curr_max = 0
    -> Loop for each element in array
        -> curr_max += arr[i]
        -> if(max_so_far < curr_max)
                max_so_far = curr_max
        -> if(curr_max < 0)
                max_curr = 0
    -> return max_so_far
*/

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int kadane_algo(int arr[],int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << kadane_algo(arr,n) << endl;

    return 0;
}

// Using Kadane's Algorithm -> Time Complexity - O(n), Space Complexity - O(1)
int kadane_algo(int arr[],int n){
    
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
