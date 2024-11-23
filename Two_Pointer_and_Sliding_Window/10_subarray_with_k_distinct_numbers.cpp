// Leetcode link - https://leetcode.com/problems/subarrays-with-k-different-integers/
// Find the number of subarrays where the distinct integers in the subarray is K

#include <bits/stdc++.h>
using namespace std;

// Generate all subarrays --> Time Complexity - O(N2), Space Complexity - O(N)
class Solution1
{
public:
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    int cnt = 0; // Counter to store the number of subarrays with exactly k distinct integers

    // Outer loop iterates over all starting points of subarrays
    for (int i = 0; i < nums.size(); i++)
    {
      set<int> s; // Set to keep track of distinct elements in the current subarray

      // Inner loop extends the subarray starting at 'i'
      for (int j = i; j < nums.size(); j++)
      {
        s.insert(nums[j]); // Insert the current element into the set

        // If the size of the set equals k, we found a valid subarray
        if (s.size() == k)
          cnt++; // Increment the count of valid subarrays
        // If the size exceeds k, we can stop exploring further for this subarray
        if (s.size() > k)
          break;
      }
    }

    return cnt; // Return the total count of subarrays with exactly k distinct integers
  }
};

// Subsets(==K) = Subsets(<=K) - Subsets(<=K-1) --> Time Complexity - O(N), Space Complexity - O(N)
class Solution2
{
public:
  // Helper function to calculate subarrays with at most K distinct integers
  int subarrayWithLessThanK(vector<int> &nums, int k)
  {
    if (k <= 0)
      return 0;                 // If K is 0 or less, no valid subarray exists
    int cnt = 0;                // Count of subarrays
    int l = 0;                  // Left pointer
    unordered_map<int, int> mp; // Frequency map

    for (int r = 0; r < nums.size(); r++)
    {                // Right pointer
      mp[nums[r]]++; // Increment frequency of the current element
      while (mp.size() > k)
      {                       // Shrink window if distinct count exceeds K
        mp[nums[l]]--;        // Decrement frequency of the leftmost element
        if (mp[nums[l]] == 0) // Remove the element if its frequency is 0
          mp.erase(nums[l]);
        l++; // Move left pointer
      }
      cnt += r - l + 1; // Add all subarrays ending at 'r'
    }
    return cnt;
  }

  // Main function to calculate subarrays with exactly K distinct integers
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    // Exactly K = At most K - At most (K - 1)
    return subarrayWithLessThanK(nums, k) - subarrayWithLessThanK(nums, k - 1);
  }
};
