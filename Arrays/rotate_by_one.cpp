// Cyclically rotate an array by one

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
void rotate_arr1(int arr[],int n);
void rotate_arr2(int arr[],int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    rotate_arr2(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}

// Simple Method - Time Complexity -> O(n) ,Space Complexity -> O(1)
void rotate_arr1(int arr[],int n){
    int temp = arr[n-1];

    for(int i=n-1;i>=0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

// Using Swap function - Time Compexity -> O(n), Space Complexity -> O(1)
void rotate_arr2(int arr[],int n){
    int i = 0, j = n - 1;

    while(i!=j){
        swap(arr[i],arr[j]);
        i++;
    }
}
