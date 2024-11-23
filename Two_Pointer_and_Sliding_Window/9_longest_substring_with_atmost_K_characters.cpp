// Practice Link - https://www.naukri.com/code360/problems/distinct-characters_2221410
// Find the length of the largest substring with atmost k characters

#include <bits/stdc++.h>
using namespace std;

// Generate all substrings --> Time Complexity - O(N2), Space Complexity - O(1)
class Solution1
{
public:
  int kDistinctChars(int k, string &str)
  {
    int maxLen = 0; // Initialize variable to track the maximum length of substring.

    // Outer loop to fix the starting point of the substring.
    for (int i = 0; i < str.size(); i++)
    {
      set<char> s; // Set to store distinct characters in the current substring.

      // Inner loop to expand the substring.
      for (int j = i; j < str.size(); j++)
      {
        s.insert(str[j]); // Add the current character to the set.

        // If the set size exceeds `k`, break the loop.
        if (s.size() > k)
          break;

        // Update the maximum length if the current substring is valid.
        maxLen = max(maxLen, j - i + 1);
      }
    }

    return maxLen; // Return the maximum length of valid substring.
  }
};

// Using Sliding Window --> Time Complexity - O(N), Space Complexity - O(k) [map store atmost k characters]
class Solution2
{
public:
  int kDistinctChars(int k, string &str)
  {
    int maxLen = 0;    // Initialize the maximum length of valid substring.
    map<char, int> mp; // Map to store the frequency of characters in the current window.
    int l = 0, r = 0;  // Initialize two pointers: left (l) and right (r).

    while (r < str.size())
    {               // Traverse the string using the right pointer.
      mp[str[r]]++; // Increment the frequency of the current character.

      // Shrink the window if distinct characters exceed `k`.
      while (mp.size() > k)
      {
        mp[str[l]]--; // Decrease frequency of the character at the left pointer.
        if (mp[str[l]] == 0)
          mp.erase(str[l]); // Remove the character from the map if its frequency is 0.
        l++;                // Move the left pointer forward to shrink the window.
      }

      maxLen = max(maxLen, r - l + 1); // Update the maximum length of the valid window.
      r++;                             // Expand the window by moving the right pointer.
    }

    return maxLen; // Return the maximum length of valid substring.
  }
};