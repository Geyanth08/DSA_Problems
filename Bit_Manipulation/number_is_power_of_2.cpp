// Check whether the given number is power of 2.

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool isPowerofTwo(long long n);

// Main Function
int main(){
    
    long long n;
    cin >> n;

    if(isPowerofTwo(n)){
        cout << "Power of two" << endl;
    }else{
        cout << "Not Power of two" << endl;
    }

    return 0;
}

// if there is only one set bit then it is power of 2 -> Time Complexity - O(logn), Space Complexity - O(1)
bool isPowerofTwo(long long n){
        
    int count = 0;
    while(n){
        count += n & 1;
        n >>=1;
    }
    
    if(count == 1) return true;
    else return false;
    
}