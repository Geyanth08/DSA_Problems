// Count number of elements in Union and Intersection Of Two Sorted Array

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int union_of_two_arrays1(int arr1[],int arr2[],int m,int n);
int union_of_two_arrays2(int arr1[],int arr2[],int m,int n);
int intersection_of_two_arrays(int arr1[],int arr2[],int m,int n);

// Main Function
int main(){

    int m,n;
    cin >> m >> n;

    int arr1[m], arr2[n];
    for(int i=0;i<m;i++){
        cin >> arr1[i];
    }
    for(int i=0;i<n;i++){
        cin >> arr2[i];
    }

    cout << intersection_of_two_arrays(arr1,arr2,m,n) << endl;

    return 0;
}

// Using Set STL -> Time Complexity - O(m+n), Space Comlpexity -> O(n+m)
int union_of_two_arrays1(int arr1[],int arr2[],int m,int n){
    
    set<int> s;

    for(int i=0; i<m; i++){
        s.insert(arr1[i]);
    }

    for(int i=0; i<n; i++){
        s.insert(arr2[i]);
    }

    /* For getting the elements in the set
    for(int i : s){
        cout << i << " " << endl;
    }*/

    return s.size();
}

// Simple Approach -> Time Comlexity - O(m+n), Space Comlexity - O(1)
int union_of_two_arrays2(int arr1[],int arr2[],int m,int n){

    int i = 0, j = 0, count = 0;

    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            i++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++; j++;
        }
        count++;
    }

    while(i < m){
        count++; i++;
    }
    while(j < n){
        count++; j++;
    }

    return count;
}

// Simple Approach -> Time Complexity - O(m+n), Space Complexity - O(1)
int intersection_of_two_arrays(int arr1[],int arr2[],int m,int n){
    int i = 0, j = 0, count = 0;

    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            i++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++; j++;
            count++;
        }
    }

    return count;
}