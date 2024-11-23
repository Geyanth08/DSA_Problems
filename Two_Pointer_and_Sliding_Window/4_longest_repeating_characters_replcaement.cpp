// Leetcode link - https://leetcode.com/problems/longest-repeating-character-replacement/description/
// find the length of the longest substring containing the same letter, atmost we can change k characters

#include <bits/stdc++.h>
using namespace std;

// Generate all substrings --> Time Complexity - O(N2), Space Complexity - O(26)
class Solution1
{
public:
  int characterReplacement(string s, int k)
  {
    int maxLen = 0;

    // Iterate over all substrings
    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i; j < s.size(); j++)
      {
        vector<int> freq(26, 0);
        int maxFreq = 0;

        // Calculate frequency of characters in substring s[i...j]
        for (int l = i; l <= j; l++)
        {
          freq[s[l] - 'A']++;
          maxFreq = max(maxFreq, freq[s[l] - 'A']);
        }

        // Calculate the number of replacements needed
        int replacements = (j - i + 1) - maxFreq;

        // Check if the substring is valid
        if (replacements <= k)
        {
          maxLen = max(maxLen, j - i + 1);
        }
      }
    }

    return maxLen;
  }
};

// Using Sliding Window --> Time Complexity - O(2N), Space Complexity - O(1)
class Solution2
{
public:
  int characterReplacement(string s, int k)
  {
    map<char, int> mp;
    int maxFreq = 0; // Track the maximum frequency of any character
    int maxLen = 0, l = 0, r = 0;

    while (r < s.size())
    {
      mp[s[r]]++;
      maxFreq = max(maxFreq, mp[s[r]]); // Update max frequency in the current window

      // If the current window needs more than `k` replacements, shrink it
      while (r - l + 1 - maxFreq > k)
      {
        mp[s[l]]--;
        if (mp[s[l]] == 0)
          mp.erase(s[l]);
        l++;
      }

      // Update the maximum valid window length
      maxLen = max(maxLen, r - l + 1);
      r++;
    }

    return maxLen;
  }
};
