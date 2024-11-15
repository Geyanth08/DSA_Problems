// Leetcode link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// find first and last position of an element in a sorted array

#include <bits/stdc++.h>
using namespace std;

// Using lower_bound and Upper_bound functions - Time Complexity - O(logN)
class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int n = nums.size();
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (lb == n or nums[lb] != target)
      ub = lb = -1;

    return {lb, ub};
  }
};

// Using normal Binary Search (we need to find first and last separatly) - Time Complexity - O(LogN)
class Solution
{
public:
  int first_occurence(vector<int> &nums, int target)
  {
    int ans = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
      {
        ans = mid;
        high = mid - 1;
      }
      else if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return ans;
  }

  int last_occurence(vector<int> &nums, int target)
  {
    int ans = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
      {
        ans = mid;
        // Here we need to right for last occurence
        low = mid + 1;
      }
      else if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return ans;
  }

  vector<int> searchRange(vector<int> &nums, int target)
  {
    int first = first_occurence(nums, target);
    if (first == -1)
      return {-1, -1};
    int last = last_occurence(nums, target);

    return {first, last};
  }
};

// If we want number of occurences of the element, we can just subtract the indexes we found above.