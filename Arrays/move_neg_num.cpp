// Move all Negative Numbers to Beginning and positive numbers to end

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // Using th idea of partition of Quick Sort -> Time Complexity - O(n), Space Complexity - O(1)
    int j = 0;
    for(int i=0;i<n;i++){
        if(arr[i] < 0){
            if(i!=j)
                swap(arr[i],arr[j]);
            j++;
        }
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;


    

    return 0;
}
