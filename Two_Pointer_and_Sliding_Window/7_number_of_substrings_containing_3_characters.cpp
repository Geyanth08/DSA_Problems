// Leetcode Link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Number of substrings containing atleast one occurrence of all these characters a,b,c

#include <bits/stdc++.h>
using namespace std;

// Generate all substrings --> Time Complexity - O(N2), Space Complexity - O(1)
class Solution1
{
public:
  int numberOfSubstrings(string s)
  {
    int cntSubstr = 0; // Counter to store the number of valid substrings.
    map<char, int> mp; // Map to track character frequencies in the current window.

    // Outer loop to fix the starting point of the substring.
    for (int i = 0; i < s.size(); i++)
    {
      mp.clear(); // Clear the map for the new starting point.

      // Inner loop to expand the substring.
      for (int j = i; j < s.size(); j++)
      {
        mp[s[j]]++; // Increment the frequency of the current character.

        // If all three characters are present, count valid substrings.
        if (mp.size() == 3)
        {
          cntSubstr += s.size() - j; // Add all possible substrings starting at `j`.
          break;                     // Exit inner loop.
        }
      }
    }

    return cntSubstr; // Return the total count of valid substrings.
  }
};

// Using Sliding Window --> Time Complexity - O(N+N), Space Complexity - O(1)
class Solution2
{
public:
  int numberOfSubstrings(string s)
  {
    int cntSubstr = 0; // Counter for valid substrings.
    map<char, int> mp; // Map to track character frequencies in the current window.
    int left = 0;      // Left pointer for the sliding window.

    // Traverse the string with the right pointer.
    for (int right = 0; right < s.size(); right++)
    {
      mp[s[right]]++; // Add the current character to the window.

      // Shrink the window until it contains all three characters.
      while (mp.size() == 3)
      {
        cntSubstr += s.size() - right; // Count all valid substrings.
        mp[s[left]]--;                 // Decrease the frequency of the left character.
        if (mp[s[left]] == 0)
          mp.erase(s[left]); // Remove the character if its frequency is 0.
        left++;              // Move the left pointer forward.
      }
    }

    return cntSubstr; // Return the total count of valid substrings.
  }
};

// Simple appraoch --> Time Complexity - O(N), Space Complexity - O(1)
// Here we check backward characters (ex - bbac, when we are at c, then we got bac all characters. minimum index of three + 1 gives substrings)
class Solution3
{
public:
  int numberOfSubstrings(string s)
  {
    int cntSubstr = 0;              // Counter for valid substrings.
    int lastseen[3] = {-1, -1, -1}; // Tracks the last seen indices of 'a', 'b', and 'c'.

    // Iterate through the string.
    for (int i = 0; i < s.size(); i++)
    {
      lastseen[s[i] - 'a'] = i; // Update the last seen index for the current character.

      // Calculate the number of valid substrings ending at index `i`.
      cntSubstr += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
    }

    return cntSubstr; // Return the total count of valid substrings.
  }
};
