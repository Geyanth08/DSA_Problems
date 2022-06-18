// Practice link - https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
// Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// ************ Using 2D DP Array ************** //

#include <bits/stdc++.h>
using namespace std;

// Using Recursion (do not consider the activity that done before day) -> Time Complexity - O(3^N), Space Complexity - O(N) for recusion stack space.
// f(day,last) - maximum points till given day with the last option on previous day
int solve(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int curMax = 0, activityPoints;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            activityPoints = points[day][i] + solve(day - 1, i, points);
            curMax = max(curMax, activityPoints);
        }
    }

    return curMax;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(n - 1, 3, points);
}

// Using Memorization -> Time Complexity - O(N*3), Space Complexity - O(N*3) + O(N)
int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
        return dp[day][last];

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[0][last] = maxi;
    }

    int curMax = 0, activityPoints;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            activityPoints = points[day][i] + solve(day - 1, i, points, dp);
            curMax = max(curMax, activityPoints);
        }
    }

    return dp[day][last] = curMax;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}

// Using Tabulation -> Time Complexity - O(N*4*3), Space Complexity - O(N*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base Conditions
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Looping
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// After space optimization -> Time Complexity - O(N*4*3), Space Complexity - O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    // Base Conditions
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Looping
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + prev[task];
                    temp[last] = max(temp[last], activity);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}
