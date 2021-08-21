// Find First and Last occurrence of an Element in Sorted Array

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int first1(int arr[],int low,int high,int n,int ele);
int last1(int arr[],int low,int high,int n,int ele);
int first2(int arr[],int ele,int n);
int last2(int arr[],int ele,int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int element;
    cin >> element;

    cout << "First Occurrence " << first2(arr,element,n) + 1 << endl;
    cout << "Last Occurrence " << last2(arr,element,n) + 1 << endl;

    return 0;
}

// Using Binary Search -> Time Complexity - O(logn), Space Complexity - O(logn)
int first(int arr[],int low,int high,int n,int ele){
    if(high >= low){
        int mid = (high+low)/2;

        if((mid == 0 || ele > arr[mid-1]) && arr[mid] == ele){
            return mid;
        }
        if(ele > arr[mid]){
            return first(arr,mid+1,high,n,ele);
        }else{
            return first(arr,low,mid-1,n,ele);
        }
    }
    return -1;
}

int last(int arr[],int low,int high,int n,int ele){
    if(high >= low){
        int mid = (low+high)/2;

        if((mid == n-1 || ele < arr[mid+1]) && arr[mid] == ele){
            return mid;
        }
        if(ele >= arr[mid]){
            return last(arr,mid+1,high,n,ele);
        }else{
            return last(arr,low,mid-1,n,ele);
        }
    }
    return -1;
}

// Reduced Space Complexity -> Time Complexity - O(logn), Space Complexity - O(1)
int first2(int arr[],int ele,int n){
    
    int low = 0, high = n-1,pos=-1;
    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid]>ele){
            high = mid-1;
        }else if(arr[mid] < ele){
            low = mid + 1;
        }else{
            pos = mid;
            high = mid - 1;
        }
    }
    return pos;
}

int last2(int arr[],int ele,int n){

    int low = 0, high = n-1, pos = -1;

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] > ele){
            high = mid - 1;
        }else if(arr[mid] < ele){
            low = mid + 1;
        }else {
            pos = mid;
            low = mid + 1;
        }
    }

    return pos;
}