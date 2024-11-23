// Leetcode link - https://leetcode.com/problems/max-consecutive-ones-iii/
// Find the maximum number of consecutive ones, if you can flip atmost k zeroes

#include <bits/stdc++.h>
using namespace std;

// Generate all subarrays and check the zeroes --> Time Complexity - O(N2), Space Complexity - O(1)
class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int maxLen = 0; // Tracks the maximum length of subarray with at most `k` zeroes.

    // Iterate through each starting point.
    for (int i = 0; i < nums.size(); i++)
    {
      int zeroes = 0; // Count of zeroes in the current subarray.

      // Expand the subarray starting from index `i`.
      for (int j = i; j < nums.size(); j++)
      {
        if (!nums[j]) // Increment zero count if a zero is found.
          zeroes++;

        if (zeroes > k) // Stop if zero count exceeds `k`.
          break;

        // Update the maximum length.
        maxLen = max(maxLen, j - i + 1);
      }
    }
    return maxLen; // Return the length of the longest valid subarray.
  }
};

// Using sliding window, shrink when number of zeroes exceeds k -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int left = 0, right = 0; // Sliding window pointers.
    int zeroes = 0;          // Count of zeroes in the current window.
    int maxLen = 0;          // Tracks the maximum length of a valid subarray.

    while (right < nums.size())
    {
      // Increment zero count if the current element is 0.
      if (nums[right] == 0)
        zeroes++;

      // If zeroes exceed k, shrink the window from the left.
      while (zeroes > k)
      {
        if (nums[left] == 0)
          zeroes--;
        left++;
      }

      // Update the maximum length of the valid subarray.
      maxLen = max(maxLen, right - left + 1);

      // Expand the window by moving the right pointer.
      right++;
    }

    return maxLen; // Return the maximum length of consecutive 1's.
  }
};
