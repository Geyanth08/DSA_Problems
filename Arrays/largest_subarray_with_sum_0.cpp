// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Compute the length of the largest subarray whose sum is zero

#include <bits/stdc++.h>
using namespace std;

// Using Hasshmp (prefix sum) -> Time Complexity - O(NlogN), Space Complexity - O(N)
class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // Your code here
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum == 0)
            {
                maxi = i + 1;
            }
            else
            {
                if (mp.find(sum) != mp.end())
                {
                    maxi = max(maxi, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }

        return maxi;
    }
};