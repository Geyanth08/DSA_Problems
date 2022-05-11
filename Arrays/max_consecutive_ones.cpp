// Leetcode link - https://leetcode.com/problems/max-consecutive-ones/
// Given Binary array, return maximum number of consecutive one's in array

#include <bits/stdc++.h>
using namespace std;

// Simple Traversal -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (max < count)
                    max = count;
                count = 0;
            }
            else
            {
                count++;
            }
        }
        if (max < count)
            max = count;
        return max;
    }
};