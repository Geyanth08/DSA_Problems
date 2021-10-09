// Find if there is a triplet sum in the array (a + b + c = X)

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool find3Numbers(int A[], int n, int X);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << find3Numbers(arr,n,target) << "\n";

    return 0;
}

// Using two pointer approach - Time Complexity - O(n^2), Space Complexity - O(1)
bool find3Numbers(int A[], int n, int X){

    vector<int> a(A,A+n);
    sort(a.begin(),a.end());
    
    for(int i=0;i<n;i++){
        int low = i+1, high = n-1;
        
        while(low < high){
            int curr_sum = a[low] + a[high] + a[i];
            if(curr_sum == X){
                return true;
            }
            if(curr_sum < X){
                low++;
            }else{
                high--;
            }
        }
    }
    
    return false;
}