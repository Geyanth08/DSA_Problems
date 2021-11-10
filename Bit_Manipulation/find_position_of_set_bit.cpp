// Find Position of Set Bit

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int findPosition(int n);

// Main Function
int main(){

    int n;
    cin >> n;

    cout << findPosition(n) << endl;

    return 0;
}

// Counting number of bits -> Time Complexity - O(logn), Space Complexity - O(1)
int findPosition(int n) {

    int count=0,digits=0;
    while(n){
        count += n & 1;
        n >>= 1;
        digits++;
        if(count > 1) return -1;
    }
    
    if(count == 0) return -1;
    return digits;
}