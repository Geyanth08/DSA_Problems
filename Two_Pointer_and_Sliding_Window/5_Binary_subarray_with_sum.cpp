// Leetcode Link - https://leetcode.com/problems/binary-subarrays-with-sum/
// find number of binary subarrays with sum goal

#include <bits/stdc++.h>
using namespace std;

// subarray with goal = subarrays with sum less than k - subarrays with sum less than k-1
// Time Complexity - O(4N), Space Complexity - O(1)
class Solution
{
public:
  // Helper function to calculate the number of subarrays with a sum less than or equal to K
  int subarraysLessThanK(vector<int> &nums, int K)
  {
    // If K is negative, there can be no valid subarray
    if (K < 0)
      return 0;

    int sum = 0;      // Current sum of the window
    int l = 0, r = 0; // Two pointers: left (l) and right (r)
    int cnt = 0;      // Count of valid subarrays

    // Expand the window by moving the right pointer
    while (r < nums.size())
    {
      sum += nums[r]; // Add the current element to the sum

      // Shrink the window if the sum exceeds K
      while (sum > K)
      {
        sum -= nums[l]; // Remove the leftmost element from the sum
        l++;            // Move the left pointer
      }

      // All subarrays ending at 'r' and starting from any index between 'l' and 'r' are valid
      cnt += r - l + 1;
      r++; // Move the right pointer
    }

    return cnt; // Return the total count of subarrays with sum <= K
  }

  // Main function to find the number of subarrays with a sum exactly equal to the goal
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    // Use the helper function to calculate the result
    return subarraysLessThanK(nums, goal) - subarraysLessThanK(nums, goal - 1);
    // Explanation:
    // - subarraysLessThanK(nums, goal) includes all subarrays with sum <= goal
    // - subarraysLessThanK(nums, goal - 1) excludes subarrays with sum == goal
  }
};
