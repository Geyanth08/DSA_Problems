// Practice link - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879
// Print Longest common Subsequence of two strings

#include <bits/stdc++.h>
using namespace std;

// Using DP array -> Time Complexity - O(N*M), Space Complexity - O(N*M)
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

    int len = dp[s.size()][t.size()];
    int i = s.size();
    int j = t.size();

    int index = len - 1;
    string str = "";
    for (int k = 0; k < len; k++)
        str += "$";

    while (i > 0 and j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            str[index] = s[i - 1];
            index--;
            i--;
            j--;
        }
        else if (s[i - 1] > t[j - 1])
            i--;
        else
            j--;
    }

    cout << str << " ";
    return 0;
}
