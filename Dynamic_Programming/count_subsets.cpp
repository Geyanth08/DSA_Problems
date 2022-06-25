// Practice link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
// You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^N), Space Complexity - O(N)
int f(int ind, int target, vector<int> &num)
{
    if (target == 0)
        return 1;
    if (ind == 0)
    {
        if (num[0] == target)
            return 1;
        return 0;
    }
    if (target < 0)
        return 0;

    int pick = f(ind - 1, target - num[ind], num);
    int notPick = f(ind - 1, target, num);

    return pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
    return f(num.size() - 1, tar, num);
}

// Using Memorization -> Time Complexity - O(N*K), Space Complexity - O(N*K) + O(N)
int f(int ind, int target, vector<int> &num, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
    {
        if (num[0] == target)
            return 1;
        return 0;
    }
    if (target < 0)
        return 0;
    if (dp[ind][target] != -1)
        dp[ind][target];

    int pick = f(ind - 1, target - num[ind], num, dp);
    int notPick = f(ind - 1, target, num, dp);

    return dp[ind][target] = pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar + 1, -1));
    return f(num.size() - 1, tar, num, dp);
}

// Using Tabulation -> Time Complexity - O(N*K), Space Complexity - O(N*K)
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar + 1, 0));

    for (int i = 0; i < num.size(); i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < num.size(); ind++)
    {
        for (int target = 1; target <= tar; target++)
        {
            int take = 0;
            if (num[ind] <= target)
                take = dp[ind - 1][target - num[ind]];
            int notTake = dp[ind - 1][target];

            dp[ind][target] = take + notTake;
        }
    }

    return dp[num.size() - 1][tar];
}

// After Space Otimization -> Time Complexity - O(N*K), Space Complexity - O(K)
int findWays(vector<int> &num, int tar)
{
    vector<int> prev(tar + 1, 0);

    prev[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int ind = 1; ind < num.size(); ind++)
    {
        vector<int> temp(tar + 1, 0);
        temp[0] = 1;
        for (int target = 1; target <= tar; target++)
        {
            int take = 0;
            if (num[ind] <= target)
                take = prev[target - num[ind]];
            int notTake = prev[target];

            temp[target] = take + notTake;
        }
        prev = temp;
    }

    return prev[tar];
}