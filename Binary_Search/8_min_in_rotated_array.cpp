// Leetcode Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// find the minimum element in the rotated array

#include <bits/stdc++.h>
using namespace std;

// The half which has the rotated element will have minimum element - Time Complexity - O(LogN)
class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int ans = INT_MAX;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] < ans)
        ans = nums[mid];
      if (nums[mid] > nums[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
    return ans;
  }
};