// Copy set bits in a range from one number to another number

#include <bits/stdc++.h>
using namespace std;

// Main function
int main(){

    int x,y;
    int l,r; // range

    cin >> x >> y >> l >> r;

    // Using Mask -> Time Complexity - O(r), Space Complexity - O(1)
    for(int i=l;i<=r;i++){

        // Mask - A number whose set bit is only at the i'th position
        int mask = 1 << (i-1);

        // if the ith position is set then we change the value of x
        if(y and mask) x = x | mask;
    }

    cout << x << endl;

    return 0;
}