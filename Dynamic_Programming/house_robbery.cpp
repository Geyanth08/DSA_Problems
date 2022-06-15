// Practice link - https://www.codingninjas.com/codestudio/problems/house-robber_839733
// Mr. X cannot rob adjacent houses it alerts police and houses are in circular way.
// Return the maximum amount of money Mr. X can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^N), Space Complexity - O(N) auxiliary stack space
long long int solve1(vector<int> &arr, int ind)
{
    if (ind == 0)
        return arr[0];
    if (ind < 0)
        return 0;

    int rob = arr[ind] + solve1(arr, ind - 2);
    int notRob = solve1(arr, ind - 1);

    return max(rob, notRob);
}

long long int houseRobber1(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];
    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr1.push_back(valueInHouse[i]);
        if (i != n - 1)
            arr2.push_back(valueInHouse[i]);
    }

    long long int ans1 = solve1(arr1, n - 2);
    long long int ans2 = solve1(arr2, n - 2);

    return max(ans1, ans2);
}

// Using Memorization -> Time Complexity - O(N), Space Complexity - O(N) + O(N) auxiliary stack space
long long int solve2(vector<int> &arr, int ind, vector<long long int> &dp)
{
    if (ind == 0)
        return arr[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int rob = arr[ind] + solve2(arr, ind - 2, dp);
    int notRob = solve2(arr, ind - 1, dp);

    return dp[ind] = max(rob, notRob);
}

long long int houseRobber2(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];

    vector<int> arr1;
    vector<int> arr2;
    vector<long long int> dp1(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr1.push_back(valueInHouse[i]);
        if (i != n - 1)
            arr2.push_back(valueInHouse[i]);
    }

    long long int ans1 = solve2(arr1, n - 2, dp1);
    vector<long long int> dp2(n, -1);
    long long int ans2 = solve2(arr2, n - 2, dp2);

    return max(ans1, ans2);
}

// Using Tabulation -> Time Complexity - O(N), Space Complexity - O(1)
long long int solve3(vector<int> &arr)
{
    int n = arr.size();
    vector<long long int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        long long int rob = arr[i];
        if (i > 1)
            rob += arr[i - 2];

        long long int notRob = 0 + arr[i - 1];

        dp[i] = max(rob, notRob);
    }

    return dp[n - 1];
}

long long int houseRobber3(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];

    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr1.push_back(valueInHouse[i]);
        if (i != n - 1)
            arr2.push_back(valueInHouse[i]);
    }

    long long int ans1 = solve3(arr1);
    long long int ans2 = solve3(arr2);

    return max(ans1, ans2);
}

// After space optimization -> Time Complexity - O(N), Space Complexity - O(1)
long long int solve4(vector<int> &arr)
{
    int n = arr.size();
    long long int prev2 = 0;
    long long int prev = arr[0];

    for (int i = 1; i < n; i++)
    {
        long long int rob = arr[i];
        if (i > 1)
            rob += prev2;

        long long int notRob = 0 + prev;

        long long curr = max(rob, notRob);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

long long int houseRobber4(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];

    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr1.push_back(valueInHouse[i]);
        if (i != n - 1)
            arr2.push_back(valueInHouse[i]);
    }

    long long int ans1 = solve4(arr1);
    long long int ans2 = solve4(arr2);

    return max(ans1, ans2);
}