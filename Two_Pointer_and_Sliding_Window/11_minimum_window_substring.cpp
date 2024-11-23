// Leetcode link - https://leetcode.com/problems/minimum-window-substring/
// Given two strings s and t. find minimum window substring of s such that every character in t is included in the window.

#include <bits/stdc++.h>
using namespace std;


// Include characters of t in a map, and check in s for all possible substrings
// Time Complexity - O(N2), Space Complexity - O(128)
class Solution1
{
public:
  string minWindow(string s, string t)
  {
    if (s.empty() || t.empty())
      return ""; // Edge case: Empty input strings

    int minLen = INT_MAX; // Initialize the minimum length
    int startIndex = -1;  // Start index of the minimum window

    // Iterate over all possible starting points
    for (int i = 0; i < s.size(); i++)
    {
      vector<int> freq(128, 0); // Frequency map for characters in `t`
      for (char c : t)
        freq[c]++;

      int count = t.size(); // Number of characters to match

      // Expand the window starting from `i`
      for (int j = i; j < s.size(); j++)
      {
        if (freq[s[j]] > 0)
          count--;    // Decrement count if a character in `t` is found
        freq[s[j]]--; // Decrement its frequency

        // If all characters in `t` are matched
        if (count == 0)
        {
          if (j - i + 1 < minLen)
          {
            minLen = j - i + 1; // Update the minimum length
            startIndex = i;     // Update the starting index
          }
          break; // Exit as soon as a valid window is found
        }
      }
    }

    // If no valid window is found, return an empty string
    return startIndex == -1 ? "" : s.substr(startIndex, minLen);
  }
};

// Using sliding window --> Time Complexity - O(N), Space Complexity - O(128)
class Solution2
{
public:
  string minWindow(string s, string t)
  {
    int n = s.size();
    int m = t.size();

    if (m > n)
      return ""; // Edge case: if t is longer than s, no solution.

    int l = 0, r = 0, minLen = INT_MAX, startIndex = -1, cnt = 0;
    vector<int> freq(128, 0);

    // Count the frequencies of characters in t.
    for (auto it : t)
      freq[it]++;

    while (r < n)
    {
      // If character at s[r] is part of t, increase count.
      if (freq[s[r]] > 0)
        cnt++;
      freq[s[r]]--;

      // When all characters of t are in the current window.
      while (cnt == m)
      {
        // Update minimum length and start index if the current window is smaller.
        if (r - l + 1 < minLen)
        {
          minLen = r - l + 1;
          startIndex = l;
        }

        // Shrink the window from the left.
        freq[s[l]]++;
        if (freq[s[l]] > 0)
          cnt--;
        l++;
      }

      // Expand the window to the right.
      r++;
    }

    // If no valid window was found, return an empty string.
    return startIndex == -1 ? "" : s.substr(startIndex, minLen);
  }
};
