// Leetcode Link - https://leetcode.com/problems/pascals-triangle/
// Construct Pascals Triangle with given number of rows

#include <bits/stdc++.h>
using namespace std;

// Getting elements of present vector from previous vector -> Time Complexity - O(N^2), Space Complexity - O(N^2)
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal_array;
        if (numRows == 1)
        {
            pascal_array = {{1}};
            return pascal_array;
        }
        if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }

        pascal_array = {{1}, {1, 1}};

        for (int i = 3; i <= numRows; i++)
        {
            vector<int> row;
            row.push_back(1);

            for (int j = 0; j < i - 2; j++)
            {
                auto it = pascal_array.back();
                row.push_back(it[j] + it[j + 1]);
            }

            row.push_back(1);
            pascal_array.push_back(row);
        }

        return pascal_array;
    }
};