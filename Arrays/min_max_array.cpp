// Minimum and Maximum of an array.

#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

// Linear Search Method.
struct Pair Min_And_Max(int arr[],int n){

    struct Pair Min_Max;
    int i;

    if(n == 1){
        Min_Max.min = arr[0];
        Min_Max.max = arr[0];

        return Min_Max;
    }

    if(arr[0] > arr[1]){
        Min_Max.min = arr[1];
        Min_Max.max = arr[0];
    }else {
        Min_Max.min = arr[0];
        Min_Max.max = arr[1];
    }

    for(i = 2; i < n; i++){
        if(arr[i] > Min_Max.max){
            Min_Max.max = arr[i];
        }else if(arr[i] < Min_Max.min){
            Min_Max.min = arr[i];
        }
    }

    return Min_Max;
}

int main(){

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    struct Pair Min_Max = Min_And_Max(arr,n);

    cout << Min_Max.min << " " << Min_Max.max << endl;

    return 0;
}