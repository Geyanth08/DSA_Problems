// Leetcode link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Given the array nums after the possible rotation and an integer target, check whether the element is present or not (includes duplicants)

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
        return true;
      // if we have an array [3 1 2 3 3 3 3 3] - we are unable to find sorted half. so we trim the search space.
      if (nums[mid] == nums[low] and nums[mid] == nums[high])
      {
        low++;
        high--;
        continue;
      }
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

    return false;
  }
};