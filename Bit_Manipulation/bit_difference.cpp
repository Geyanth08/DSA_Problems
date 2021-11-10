// Count the number of bits needed to be flipped to convert A to B

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int countBitsFlip(int a, int b);

// Main Function
int main(){
    
    int A,B;
    cin >> A >> B;

    cout << countBitsFlip(A,B) << endl;

    return 0;
}

// XOR of two numbers and counting set bits -> Time Complexity - O(logn), Space Complexity - O(1)
int countBitsFlip(int a, int b){
        
    int count = 0;
    
    int res = a ^ b;
    
    while(res){
        count += res & 1;
        res >>= 1;
    }
    
    return count;
}