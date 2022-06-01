// Practice link - https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574
// find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

#include <bits/stdc++.h>
using namespace std;

bool allocationIsPossible(long long m, vector<int> &time, int n)
{
    int days = 1;
    long long currTime = 0;

    for (int i = 0; i < time.size(); i++)
    {
        if (time[i] > m)
            return false;
        if (currTime + time[i] > m)
        {
            days++;
            currTime = time[i];
        }
        else
            currTime += time[i];
    }

    if (days > n)
        return false;
    return true;
}

// Partition of Time relative to books -> Time Complexity - O(NlogN), Space Coplexity - O(1)
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long high = 0;
    int low = -1;
    for (int i = 0; i < time.size(); i++)
    {
        high += time[i];
        low = min(low, time[i]);
    }

    long long minTime = -1;

    while (low <= high)
    {
        long long mid = (low + high) >> 1;
        if (allocationIsPossible(mid, time, n))
        {
            minTime = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}