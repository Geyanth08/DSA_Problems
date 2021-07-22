// Reverse the given array or string

#include <iostream>
using namespace std;

// Time Complexity - O(n)
void iterativeMethod(int arr[],int start,int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }

}

// Time Complexity - O(n)
void recursionMethod(int arr[],int start, int end){
    
    if(start >= end){
        for(int i=0;i<10;i++){
            cout << arr[i] << " ";
        }
        return;
    }

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    recursionMethod(arr,start+1,end-1);
        
}

int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int start = 0;
    int end = 9;

    iterativeMethod(arr,start,end);
    recursionMethod(arr,start,end);
    
    return 0;
}