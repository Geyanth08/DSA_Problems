// Leetcode link - https://leetcode.com/problems/palindrome-partitioning/submissions/
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

#include <bits/stdc++.h>
using namespace std;

// Check whether string is palindrome then partition -> Time Complexity - O(2^N*K*(N/2)), Space Complexity - O(K*N)
class Solution
{
public:
    void func(int ind, string s, vector<string> &path, vector<vector<string>> &ans)
    {
        if (ind == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        func(0, s, path, ans);
        return ans;
    }
};