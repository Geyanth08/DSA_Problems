// Practice link - https://www.codingninjas.com/codestudio/problems/1062582
// You are given two versions numbers A and B as a string. Your task is to compare them and find out which one of them is a newer version.

#include <bits/stdc++.h>
using namespace std;

// Comparing each part of both versions -> Time Complexity - O(N + M), Space Complexity - O(1)
int compareVersions(string a, string b)
{
    int i = 0, j = 0;
    int n = a.length(), m = b.length();
    long long n1, n2;

    while (i < n or j < m)
    {
        n1 = 0, n2 = 0;

        while (i < n and a[i] != '.')
        {
            n1 = n1 * 10 + (a[i] - '0');
            i++;
        }

        while (j < m and b[j] != '.')
        {
            n2 = n2 * 10 + (b[j] - '0');
            j++;
        }

        if (n1 > n2)
            return 1;
        else if (n1 < n2)
            return -1;
        i++;
        j++;
    }

    return 0;
}