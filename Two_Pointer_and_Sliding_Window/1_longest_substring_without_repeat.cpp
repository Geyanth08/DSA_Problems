// Leetcode link - https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
// Find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

// Calculate all possible substrings --> Time Complexity - O(N2), Space Complexity - O(256)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Handle edge case: single space string.
        if (s == " ")
            return 1;

        int maxLen = 0; // Tracks the longest substring length.

        // Iterate through each character as the starting point.
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> hash(256, 0); // Tracks character frequencies.

            // Expand substring starting from index `i`.
            for (int j = i; j < s.size(); j++)
            {
                hash[s[j]]++; // Increment character count.

                // Break if duplicate character is found.
                if (hash[s[j]] > 1)
                    break;

                // Update maximum length.
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen; // Return the longest substring length.
    }
};

// Using map (To store character and its index) -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mp(256, -1); // Map to store the last index of each character.

        int left = 0, right = 0; // Pointers for the sliding window.
        int len = 0;             // Tracks the maximum length of the substring.
        int n = s.size();

        // Sliding window approach
        while (right < n)
        {
            // If character already appeared, move `left` to the next position after its last occurrence.
            if (mp[s[right]] != -1)
                left = max(mp[s[right]] + 1, left);

            // Update the last occurrence of the current character.
            mp[s[right]] = right;

            // Update the maximum length of the substring found so far.
            len = max(len, right - left + 1);

            // Move the right pointer forward.
            right++;
        }

        return len; // Return the length of the longest substring.
    }
};
