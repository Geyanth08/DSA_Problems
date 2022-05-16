// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// number of jobs done and the maximum profit.

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// Sorting the Profit -> Time Complexity - O(NlogN), Space Compexity - O(N)
class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, [](const Job &a, const Job &b)
             { return a.profit > b.profit; });
        int max_dead_line = 0;
        for (int i = 0; i < n; i++)
        {
            max_dead_line = max(max_dead_line, arr[i].dead);
        }

        vector<int> slot(max_dead_line + 1, -1);
        int count_jobs = 0, max_profit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    count_jobs++;
                    max_profit += arr[i].profit;
                    break;
                }
            }
        }

        vector<int> ans;
        ans.push_back(count_jobs);
        ans.push_back(max_profit);

        return ans;
    }
};