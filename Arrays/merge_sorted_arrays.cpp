// Leetcode link - https://leetcode.com/problems/merge-sorted-array/
// Given two sorted arrays, combine both sorted arrays into one array in ascending order

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Two Pointer Approach -> Time Complexity - O(m*n), Space Complexity - O(1)

    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        if (n == 0 and m == 0)
            return;
        if (n == 0)
            return;
        if (m == 0)
        {
            num1 = num2;
            return;
        }

        int j = 0, k = 0;
        for (int i = 0; i < m; i++)
        {
            if (num1[j] > num2[k])
            {
                swap(num1[j], num2[k]);
                sort(num2.begin(), num2.end());
            }
            j++;
        }
        for (int i = m; i < m + n; i++)
        {
            num1[i] = num2[i - m];
        }
    }
};