// GFG link - https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
// longest subarray such that we should have only 2 types of fruits in the baskets.

#include <bits/stdc++.h>
using namespace std;

// Generate all subsets and make sure that subarray contains only two type of integers --> Time Complexity - O(N2)
// Space Complexity - O(1)
class Solution
{
public:
  int totalFruits(vector<int> &arr)
  {
    int maxFruits = 0;

    // Iterate through each starting index.
    for (int i = 0; i < arr.size(); i++)
    {
      set<int> s; // Set to track unique fruit types in the window.

      // Expand the window starting from index `i`.
      for (int j = i; j < arr.size(); j++)
      {
        s.insert(arr[j]); // Add fruit to the set.

        // Stop if more than 2 types of fruits are in the set.
        if (s.size() > 2)
          break;

        // Update the maximum length of a valid subarray.
        maxFruits = max(maxFruits, j - i + 1);
      }
    }
    return maxFruits; // Return the maximum number of fruits.
  }
};

// Use sliding window --> Time Complexity - O(2N), Space Complexity - O(1)
class Solution
{
public:
  int totalFruits(vector<int> &arr)
  {
    unordered_map<int, int> fruitCount; // Tracks the count of each fruit type.
    int left = 0, maxFruits = 0;

    // Iterate through the array using the right pointer.
    for (int right = 0; right < arr.size(); right++)
    {
      fruitCount[arr[right]]++; // Add the current fruit to the count.

      // Shrink the window if there are more than 2 types of fruits.
      while (fruitCount.size() > 2)
      {
        fruitCount[arr[left]]--;
        if (fruitCount[arr[left]] == 0)
          fruitCount.erase(arr[left]); // Remove fruit type with 0 count.
        left++;                        // Move the left pointer.
      }

      // Update the maximum length of a valid subarray.
      maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits; // Return the maximum number of fruits.
  }
};
