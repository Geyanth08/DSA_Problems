// Divide Two Integers without using multiplication, division and mod operator

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int divide(long long dividend, long long divisor);

// Main Function
int main(){

    int a,b;
    cin >> a >> b;

    int result = divide(a,b);
    cout << result << endl;

    return 0;
}

// dividend = quotient*divisor + remainder -> Time Complexity - O(loga), Space Complexity - O(1)
int divide(long long dividend, long long divisor){

    // check result will be positive or negative
    int sign = ((dividend < 0)^(divisor < 0)) ? -1 : 1;

    divisor = abs(divisor);
    dividend = abs(dividend);

    long long quotient = 0, temp = 0;

    for(int i=31;i>=0;i--){
        if(temp + (divisor << i) <= dividend){
            temp += divisor << i;
            quotient |= 1LL << i;
        }
    }

    if(sign == -1){
        quotient = -quotient;
    }

    return quotient;
}