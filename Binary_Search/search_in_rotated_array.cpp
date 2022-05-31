// Leetcode link - https://leetcode.com/problems/search-in-rotated-sorted-array/
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

#include <bits/stdc++.h>
using namespace std;

// search in a half which is sorted -> Time Complexity - O(logN), Space Complexity - O(1)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target and nums[mid] >= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target and target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};