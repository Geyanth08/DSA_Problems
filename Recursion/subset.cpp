// Leetcode link - https://leetcode.com/problems/subsets-ii/
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set). No DUPLICATES

#include <bits/stdc++.h>
using namespace std;

// checking for same elements while recursion -> Time Complexity - O(2^N*N), Space Complexity - O(2^N)
class Solution
{
public:
    void func(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind and nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            func(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        func(0, nums, ds, ans);
        return ans;
    }
};