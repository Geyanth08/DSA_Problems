// Leetcode link - https://leetcode.com/problems/set-matrix-zeroes/
// If element is Zero then set entire row and column to zeroes

#include <bits/stdc++.h>
using namespace std;

// Simple Traversal -> Time Complexity - O(2*M*N), Space Complexity - O(2*N)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        // for storing flags
        vector<bool> rows(matrix.size(), false);
        vector<bool> col(matrix[0].size(), false);

        // Setting flags when a row or column has zero
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = true;
                    col[j] = true;
                    continue;
                }
            }
        }

        // check whether flag is true for either row or column
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (rows[i] or col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};