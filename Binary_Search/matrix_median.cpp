// Practice link - https://www.codingninjas.com/codestudio/problems/873378
// find the overall median of the matrix i.e if all elements of the matrix are written in a single line,
// then you need to return the median of that linear array.

#include <bits/stdc++.h>
using namespace std;

int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0;
    int h = row.size() - 1;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (row[m] <= mid)
            l = m + 1;
        else
            h = m - 1;
    }
    return l;
}

// comparing with 1 to 1e9 numbers -> Time Complexity - O(32*N*logM), Space Complexity - O(1)
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1;
    int high = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(matrix[i], mid);
        }

        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}