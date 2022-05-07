// Leetcode link - https://leetcode.com/problems/majority-element/
// Find Majority Element from the array (i.e., a number which appears more than N/2 times)

#include <bits/stdc++.h>
using namespace std;

// Using Moore's Voting Algorithm -> Time Complexity - O(n), Space Complexity - O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int count = 0;
        int majority = 0;

        for (auto i : nums)
        {
            if (count == 0)
            {
                majority = i;
            }
            if (majority == i)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return majority;
    }
};