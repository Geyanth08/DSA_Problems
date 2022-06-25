// Practice link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628
// Count number of subsets with difference D

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^N), Space Complexity - O(N)
int mod = (int)1e9 + 7;
int f(int ind, int target, vector<int> &arr)
{
    if (ind == 0)
    {
        if (target == 0 and arr[0] == 0)
            return 2;
        if (target == 0 or arr[0] == target)
            return 1;
        return 0;
    }

    int pick = 0;
    if (arr[ind] <= target)
        pick = f(ind - 1, target - arr[ind], arr);
    int notPick = f(ind - 1, target, arr);

    return (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int tot = 0;
    for (int i = 0; i < n; i++)
        tot += arr[i];

    if (tot - d < 0)
        return 0;
    if ((tot - d) % 2)
        return 0;

    int s = (tot - d) / 2;
    return f(n - 1, s, arr);
}

// Using Memorization -> Time Complexity - O(N*K), Space Complexity - O(N*K) + O(N)
int mod = (int)1e9 + 7;
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 and arr[0] == 0)
            return 2;
        if (target == 0 or arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int pick = 0;
    if (arr[ind] <= target)
        pick = f(ind - 1, target - arr[ind], arr, dp);
    int notPick = f(ind - 1, target, arr, dp);

    return dp[ind][target] = (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int tot = 0;
    for (int i = 0; i < n; i++)
        tot += arr[i];

    if (tot - d < 0)
        return 0;
    if ((tot - d) % 2)
        return 0;

    int s = (tot - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    return f(n - 1, s, arr, dp);
}
