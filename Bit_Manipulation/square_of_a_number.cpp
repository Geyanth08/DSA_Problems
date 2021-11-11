// Calculate Square of a Number without using *,/,pow()

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int squareOfNumber1(int n);
int squareOfNumber2(int n);

// Main Function
int main(){

    int n;
    cin >> n;

    cout << squareOfNumber2(n) << endl;

    return 0;
}

// Repeatedly add n -> Time Complexity - O(n), Space Complexity - O(1)
int squareOfNumber1(int n){

    if(n < 0) n = -n;

    int result = 0;
    for(int i=0; i<n; i++){
        result += n;
    }

    return result;
}

/*
    if n is even
        n = 2*x
        n^2 = 4*x^2
    if n is odd
        n = 2*x + 1
        n^2 = 4*x^2 + 4*x + 1
*/
// Using right and left shift operators -> Time Complexity - O(logn), Space Complexity - O(1)
int squareOfNumber2(int n){
    
    if(n == 0) return 0;
    if(n < 0) n = -n;

    int x = n >> 1;

    if(n & 1) return ((squareOfNumber2(x) << 2) + (x << 2) + 1);
    else return (squareOfNumber2(x) << 2);
}