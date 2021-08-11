// Sort 0,1,2 values in an array - Commonly Known as Dutch Nation Flag Problem

#include <bits/stdc++.h>
using namespace std;

// Main Function
int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // Using DNF Algorithm -> Time Comlexity - O(n), Space Complexity -> O(1)
    int low = 0, mid = 0, high = n - 1;

    while(mid <= high){
        switch(arr[mid]){
            case 0:
                swap(arr[low++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high--]);
                break;
        }
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}

