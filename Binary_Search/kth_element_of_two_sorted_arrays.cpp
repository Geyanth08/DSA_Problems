// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K
// find the element that would be at the k’th position of the final sorted array.

#include <bits/stdc++.h>
using namespace std;

// partition the elements -> Time Complexity - O(min(logN,logM)), Space Complexity - O(1)
class Solution
{
public:
    int kthElement(int row1[], int row2[], int n, int m, int k)
    {
        if (n > m)
            return kthElement(row2, row1, m, n, k);

        int low = max(0, k - m), high = min(k, n);

        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;

            int left1 = cut1 == 0 ? -2147483648 : row1[cut1 - 1];
            int left2 = cut2 == 0 ? -2147483648 : row2[cut2 - 1];
            int right1 = cut1 == n ? 2147483647 : row1[cut1];
            int right2 = cut2 == m ? 2147483647 : row2[cut2];

            if (left1 <= right2 and left2 <= right1)
            {
                return max(left1, left2);
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 1;
    }
};