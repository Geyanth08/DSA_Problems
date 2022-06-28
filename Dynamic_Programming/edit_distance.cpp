// Practice link - https://www.codingninjas.com/codestudio/problems/edit-distance_630420
// You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.
// Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations: delete, insert, replace

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - Exponential, Space Complexity - O(N+M)
int f(int i, int j, string s, string t)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (s[i] == t[j])
        return f(i - 1, j - 1, s, t);
    return 1 + min(f(i - 1, j - 1, s, t), min(f(i - 1, j, s, t), f(i, j - 1, s, t)));
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    return f(n - 1, m - 1, str1, str2);
}

// Using Memorization -> Time Complexity - O(N*M), Space Complexity - O(N*M) + O(M+N)
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = f(i - 1, j - 1, s, t, dp);
    return dp[i][j] = 1 + min(f(i - 1, j - 1, s, t, dp), min(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp)));
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, str1, str2, dp);
}

// Using Tabulation -> Time Complexity - O(N*M), Space Complexity - O(N*M)
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    return dp[n][m];
}