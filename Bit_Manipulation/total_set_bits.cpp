// Total Count of SET bits for all numbers from 1 to n

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int countSetBits(int n);

// Main Function
int main(){
    int n;
    cin >> n;

    cout << countSetBits(n) << endl;

    return 0;
}

// Iterate till the number of bits in the number -> Time Complexity - O(logn), Space Complexity - O(1)
int countSetBits(int n){

    // To compensate 0
    n = n+1;
    
    // No of set bits in LSB
    int count = n/2;
    
    int powerOf2 = 2;
    while(powerOf2 <= n){
        
        // Total number of 0 pairs and 1 pairs in current position
        int currTotalPairs = n/powerOf2;
        
        count += (currTotalPairs/2)*powerOf2;
        
        if(currTotalPairs & 1){
            count += n % powerOf2;
        }
        
        powerOf2 <<= 1;
    }
    
    return count;
}