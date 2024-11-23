// Leetcode Link - https://leetcode.com/problems/count-number-of-nice-subarrays/
// Number of Subarrays having K odd numbers

#include <bits/stdc++.h>
using namespace std;

// Generate all subarrays --> Time Complexity - O(N2), Space Complexity - O(1)
class Solution1
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int cnt = 0; // Count of subarrays with exactly 'k' odd numbers
    int odd = 0; // Variable to count the number of odd elements in the current subarray

    // Iterate over all possible starting indices of subarrays
    for (int i = 0; i < nums.size(); i++)
    {
      odd = 0; // Reset the odd count for the current starting index

      // Iterate over all possible ending indices of subarrays starting at 'i'
      for (int j = i; j < nums.size(); j++)
      {
        if (nums[j] % 2)
        {
          odd++; // Increment the odd count if the current element is odd
        }

        // If the number of odd elements equals 'k', count this subarray
        if (odd == k)
        {
          cnt++;
        }
      }
    }

    return cnt; // Return the total count of subarrays with exactly 'k' odd numbers
  }
};

// Convert the array into binary array (Problem - binary subarrays with sum k)
// Time Complexity - O(4N), Space Complexity - O(1)
class Solution2
{
public:
  // Helper function to calculate subarrays with at most K odd numbers
  int subarraysLessThanK(vector<int> &nums, int K)
  {
    // If K is negative, there cannot be any valid subarray
    if (K < 0)
      return 0;

    int sum = 0;      // Tracks the count of odd numbers in the current window
    int l = 0, r = 0; // Left and right pointers for the sliding window
    int cnt = 0;      // Total count of subarrays with at most K odd numbers

    // Expand the window by moving the right pointer
    while (r < nums.size())
    {
      sum += nums[r] % 2; // Add 1 if nums[r] is odd, else add 0

      // Shrink the window from the left if the number of odd numbers exceeds K
      while (sum > K)
      {
        sum -= nums[l] % 2; // Remove the contribution of nums[l]
        l++;                // Move the left pointer forward
      }

      // Add the count of subarrays ending at the current right pointer
      cnt += r - l + 1;
      r++; // Move the right pointer forward
    }
    return cnt; // Return the total count
  }

  // Main function to calculate subarrays with exactly K odd numbers
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    // Use the property: exactly K = at most K - at most (K-1)
    return subarraysLessThanK(nums, k) - subarraysLessThanK(nums, k - 1);
  }
};
