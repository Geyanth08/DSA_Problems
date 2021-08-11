// Find the Kth Minimum element in Array

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int kth_min(int arr[],int k, int n);
int kth_min_stl(int arr[],int k,int n);

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

    cout << kth_min_stl(arr,k,n);

    return 0;
}

// Using Sort function -> Time Complexity - O(nlogn), Space Complexity - O(1)
int kth_min(int arr[],int k,int n){
    sort(arr,arr + n);

    return arr[k-1];
}

// Using Set STL -> Time Complexity - O(n), Space Complexity - O(n);
int kth_min_stl(int arr[],int k,int n){

    set<int> s(arr,arr+n);
    set<int>::iterator it = s.begin();

    advance(it, k-1);

    return *it;
}