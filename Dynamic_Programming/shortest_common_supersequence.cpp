// Practice link - https://www.codingninjas.com/codestudio/problems/shortest-supersequence_424449
// Given two strings, ‘A’ and ‘B’. Return the shortest supersequence string ‘S’, containing both ‘A’ and ‘B’ as its subsequences. If there are multiple answers, return any of them.

#include <bits/stdc++.h>
using namespace std;

// Traverse DP array from bottom-right -> Time Complexity - O(N*M), Space Complexity - O(N*M)
string shortestSupersequence(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

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

    int len = dp[s.size()][t.size()];
    int i = s.size();
    int j = t.size();

    int index = len - 1;
    string str = "";

    while (i > 0 and j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            str += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str += s[i - 1];
            i--;
        }
        else
        {
            str += t[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        str += s[i - 1];
        i--;
    }

    while (j > 0)
    {
        str += t[j - 1];
        j--;
    }

    reverse(str.begin(), str.end());
    return str;
}