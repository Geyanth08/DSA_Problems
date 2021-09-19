// Find the middle element from given three numbers

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int middle(int A, int B, int C);

// Main Function
int main(){
    int a,b,c;
    cin >> a >> b >> c;

    cout << middle(a,b,c) << endl;
    return 0;
}

// By Comparing - Time Complexity - O(1), Spaec Comlexity - O(1)
int middle(int A, int B, int C){

    if((A>B and A<C) || (A>C and A<B)){
        return A;
    }else if((B>A and B<C) || (B>C and B<A)){
        return B;
    }else{
        return C;
    }
}