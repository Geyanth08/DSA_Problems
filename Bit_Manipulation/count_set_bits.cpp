// Count number of set bits (No of 1's) in a NUMBER

#include <bits/stdc++.h>
using namespace std;

// Function Declartion
int count_bits(int n);
int recursive_count_bits(int n);

// Main Function
int main(){

    int n;
    cin >> n;

    cout << recursive_count_bits(n);

    return 0;
}

// Simple Method - Time Complexity -> O(logn), Space Comlexity -> O(1)
int count_bits(int n){
    int count = 0;

    while(n){
        count += n & 1;
        n >>= 1;
    }

    return count;
}

// Using Recursion - Time Comlexity -> O(logn), Space Complexity -> O(1)
int recursive_count_bits(int n){
    if(n == 0)
     return 0;
    
    return (n & 1) + recursive_count_bits(n >> 1);
}