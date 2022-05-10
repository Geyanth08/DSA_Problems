// Leetcode link - https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
// Find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

// Using map (To store character and its index) -> Time Complexity - O(N), Space Complexity - O(N)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mp(256, -1);

        int left = 0, right = 0;
        int len = 0;
        int n = s.size();

        while (right < n)
        {
            if (mp[s[right]] != -1)
                left = max(mp[s[right]] + 1, left);

            mp[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};