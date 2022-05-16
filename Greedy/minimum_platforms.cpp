// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// minimum number of platforms required for the railway station so that no train is kept waiting.

#include <bits/stdc++.h>
using namespace std;

// Sorting both arrival and departure time -> Time Complexity - O(NlogN), Space Complexity - O(N)
class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platform = 1;
        int max_platforms = 1;
        int i = 1, j = 0;

        while (i < n and j < n)
        {
            if (arr[i] <= dep[j])
            {
                platform++;
                i++;
            }
            else if (arr[i] > dep[j])
            {
                platform--;
                j++;
            }

            if (platform > max_platforms)
            {
                max_platforms = platform;
            }
        }

        return max_platforms;
    }
};