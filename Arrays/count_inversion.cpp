// count inversion in an array.

// Two elements a[i] and a[j] form a inversion if a[i] > a[j] and i > j

#include <bits/stdc++.h>
using namespace std;

// Function Declarations
int count_inversions1(int arr[],int n);
int merge(int arr[],int temp[],int left,int mid, int right);
int mergesort(int arr[],int temp[],int left,int right);
int count_inversions2(int arr[],int n);

// Main Function
int main(){

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << count_inversions1(arr,n) << endl;
}

// Using Nested Loop - Time Complexity -> O(n^2), Space Complexity -> O(1)
int count_inversions1(int arr[],int n){
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }

    return count;
}

// Using Merge Sort - Time Complexity -> O(nlogn), Space Complexity -> O(n) temp array
int count_inversions2(int arr[],int n){
    int *temp = new int[n];
    return mergesort(arr,temp,0,n-1);
}

int merge(int arr[],int temp[],int left,int mid, int right){
    int i=left,j=mid,k=left;
    int count = 0;

    while((i <= (mid - 1)) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else {
            temp[k++] = arr[j++];

            count += (mid - i);
        }
    }

    while(i <= (mid - 1)){
        temp[k++] = arr[i++];
    }

    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(int i=left;i<right;i++){
        arr[i] = temp[i];
    }

    return count;
}

int mergesort(int arr[],int temp[],int left,int right){
    int mid,count = 0;

    if(right > left){
        mid = (left + right)/2;

        count += mergesort(arr,temp,left,mid);
        count += mergesort(arr,temp,mid+1,right);

        count += merge(arr,temp,left,mid+1,right);
    }

    return count;
}