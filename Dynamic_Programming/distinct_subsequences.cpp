// Practice link - https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256
// We are given two strings, ‘TEXT' and ‘S’. We have to calculate the no. of subsequences of ‘TEXT’, which are equal to ‘S’. Since the answer can be very large print it modulo (10^9)+7.

#include <bits/stdc++.h>
using namespace std;

int mod = 1000000000 + 7;

// Using Recursion -> Time Complexity - Expontential, Space Complexity - O(N+M)
int f(int i, int j, string t, string s)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (t[i] == s[j])
        return (f(i - 1, j - 1, t, s) + f(i - 1, j, t, s)) % mod;
    else
        return f(i - 1, j, t, s) % mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    return f(lt - 1, ls - 1, t, s);
}

// Using Memorization -> Time Complexity - O(M*N), Space Complexity - O(N*M) + O(N+M)
int f(int i, int j, string t, string s, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (t[i] == s[j])
        return dp[i][j] = (f(i - 1, j - 1, t, s, dp) + f(i - 1, j, t, s, dp)) % mod;
    else
        return dp[i][j] = f(i - 1, j, t, s, dp) % mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return f(lt - 1, ls - 1, t, s, dp);
}

// Using Tabulation -> Time Complexity - O(N*M), Space Complexity - O(N*M)
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, 0));

    for (int i = 0; i < lt + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < lt + 1; i++)
    {
        for (int j = 1; j < ls + 1; j++)
        {
            if (t[i - 1] == s[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[lt][ls];
}

// After Space Optimization -> Time Complexity - O(N*M), Space Complexity - O(M)
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<int> prev(ls + 1, 0);

    prev[0] = 1;

    for (int i = 1; i < lt + 1; i++)
    {
        for (int j = ls + 1; j >= 1; j--)
        {
            if (t[i - 1] == s[j - 1])
                prev[j] = (prev[j - 1] + prev[j]) % mod;
            else
                prev[j] = prev[j];
        }
    }
    return prev[ls];
}