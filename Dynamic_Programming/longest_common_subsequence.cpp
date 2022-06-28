// Practice link - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879
// Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^(M*N)), Space Complexity - O(M*N)
int f(int ind1, int ind2, string s, string t)
{
    if (ind1 < 0 or ind2 < 0)
        return 0;

    if (s[ind1] == t[ind2])
        return 1 + f(ind1 - 1, ind2 - 1, s, t);
    return max(f(ind1 - 1, ind2, s, t), f(ind1, ind2 - 1, s, t));
}

int lcs(string s, string t)
{
    return f(s.size() - 1, t.size() - 1, s, t);
}

// Using Memorization -> Time Complexity - O(N*M), Space Complexity - O(N*M) + O(N*M)
int f(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
    if (ind1 < 0 or ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1] == t[ind2])
        return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
    return dp[ind1][ind2] = max(f(ind1 - 1, ind2, s, t, dp), f(ind1, ind2 - 1, s, t, dp));
}

int lcs(string s, string t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return f(s.size() - 1, t.size() - 1, s, t, dp);
}

// Using Tabulation -> Time Complexity - O(N*M), Space Complexity - O(N*M)
int lcs(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));

    for (int i = 0; i <= s.size(); i++)
        dp[i][0] = 0;
    for (int j = 0; j <= t.size(); j++)
        dp[0][j] = 0;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s.size()][t.size()];
}