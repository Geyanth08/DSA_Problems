// Number of Perfect Squares less than a given Number N.

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int countSquares(int N);

// Main Function
int main(){
    int n;
    cin >> n;

    cout << countSquares(n) << endl;
    return 0;
}

// Simple Approach -> Time Complexity - O(1), Space Complexity - O(1)
int countSquares(int N) {

    if(ceil((double)sqrt(N)) == floor((double)sqrt(N))){
        return sqrt(N)-1;
    }else{
        return sqrt(N);
    }
}