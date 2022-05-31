// Leetcode link - https://leetcode.com/problems/single-element-in-a-sorted-array/
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.

#include <bits/stdc++.h>
using namespace std;

// checking for break point -> Time Complexity - O(logN), Space Complexity - O(1)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == nums[mid ^ 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};