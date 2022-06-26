// Practice link - https://www.codingninjas.com/codestudio/problems/981270
// Given a string ‘STR’ of length 'N'. Implement the atoi function. If there are no numbers in the string, return 0.

#include <bits/stdc++.h>
using namespace std;

// Using ASCII values -> Time Complexity - O(N), Space Complexity - O(1)
int atoi(string str)
{
    int n = str.length();
    int num = 0;
    int minus = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[0] == '-')
            minus = 1;
        if ((str[i] - '0') <= 9 and (str[i] - '0') >= 0)
        {
            num = num * 10 + (str[i] - '0');
        }
    }

    if (minus % 2)
        return -num;
    return num;
}