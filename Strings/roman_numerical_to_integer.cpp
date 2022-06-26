// Practice link - https://www.codingninjas.com/codestudio/problems/981308
// Given a string that represents a roman number. Convert the roman number to an integer and return it.

#include <bits/stdc++.h>
using namespace std;

// Traverse from backward -> Time Complexity - O(N), Space Complexity - O(1)
int romanToInt(string s)
{
    int n = s.size();
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int num = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 and m[s[i]] < m[s[i + 1]])
            num -= m[s[i]];
        else
            num += m[s[i]];
    }

    return num;
}
