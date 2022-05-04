// Leetcode link - https://leetcode.com/problems/rotate-image/
// Given 2D matrix image, rotate the image by 90 degrees

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Transpose and reverse every row -> Time Complexity - O(N^2), Space Complexity - O(1)
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};