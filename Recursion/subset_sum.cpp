// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
// Given a list arr of N integers, print sums of all subsets in it.

#include <bits/stdc++.h>
using namespace std;

// Every element has only two options either you pick or not pick -> Time Complexity - O(2^Nlog(2^N)), Space Complexity - O(2^N)
class Solution
{
public:
    void func(int ind, int sum, int n, vector<int> &arr, vector<int> &subsets)
    {
        if (ind == n)
        {
            subsets.push_back(sum);
            return;
        }

        // Pick element
        func(ind + 1, sum + arr[ind], n, arr, subsets);

        // Do not pick element
        func(ind + 1, sum, n, arr, subsets);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subsets;
        func(0, 0, N, arr, subsets);
        sort(subsets.begin(), subsets.end());
        return subsets;
    }
};