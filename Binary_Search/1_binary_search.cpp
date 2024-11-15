// Leetcode link - https://leetcode.com/problems/binary-search/
// Given a sorted array, search the given element

#include <bits/stdc++.h>
using namespace std;

// Iterative Approach -> Time Complexity - O(logN)
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int low = 0, high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
};

// Recursive Approach -> Time Complexity - O(logN) 
class Solution
{
public:
  int bs(vector<int> &nums, int low, int high, int target)
  {
    if (low > high)
      return -1;

    int mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      return bs(nums, low, mid - 1, target);
    else
      return bs(nums, mid + 1, high, target);
  }
  int search(vector<int> &nums, int target)
  {
    return bs(nums, 0, nums.size() - 1, target);
  }
};

// OVERFLOW CASE
// when we have an array of size [0, INT_MAX] then we may get overflow when we perform mid = INT_MAX + INT_MAX
// Solutions: 1) use long long 2) mid = low + (high - low)/2 