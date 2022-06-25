// Practice link - https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
// Note - Each element can be taken infinte number of times

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - Exponential, Space Complexity - >O(N)
int f(int ind, int target, vector<int> &num)
{
    if (ind == 0)
    {
        if (target % num[0] == 0)
            return target / num[0];
        else
            return 1e9;
    }

    int take = 1e9;
    if (target >= num[ind])
        take = 1 + f(ind, target - num[ind], num);
    int notTake = 0 + f(ind - 1, target, num);

    return min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    int elements = f(n - 1, x, num);

    if (elements >= 1e9)
        return -1;
    else
        return elements;
}

// Using Memorization -> Time Complexity - O(N*T), Space Complexity - O(N*T) + O(N)
int f(int ind, int target, vector<int> &num, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target % num[0] == 0)
            return target / num[0];
        else
            return 1e9;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int take = 1e9;
    if (target >= num[ind])
        take = 1 + f(ind, target - num[ind], num, dp);
    int notTake = 0 + f(ind - 1, target, num, dp);

    return dp[ind][target] = min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int elements = f(n - 1, x, num, dp);

    if (elements >= 1e9)
        return -1;
    else
        return elements;
}

// Using Tabulation -> Time Complexity - O(N*T), Space Complexity - O(N*T)
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= x; tar++)
        {
            int take = 1e9;
            if (tar >= num[ind])
                take = 1 + dp[ind][tar - num[ind]];
            int notTake = dp[ind - 1][tar];

            dp[ind][tar] = min(take, notTake);
        }
    }

    int elements = dp[n - 1][x];
    if (elements >= 1e9)
        return -1;
    else
        return elements;
}

// After space optimization -> Time Complexity - O(N*T), Space Complexity - O(T)
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x + 1, 0);

    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            prev[i] = i / num[0];
        else
            prev[i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> temp(x + 1, 0);
        for (int tar = 0; tar <= x; tar++)
        {
            int take = 1e9;
            if (tar >= num[ind])
                take = 1 + temp[tar - num[ind]];
            int notTake = prev[tar];

            temp[tar] = min(take, notTake);
        }
        prev = temp;
    }

    int elements = prev[x];
    if (elements >= 1e9)
        return -1;
    else
        return elements;
}