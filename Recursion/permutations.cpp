// Leetcode link - https://leetcode.com/problems/permutations/
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

// Using swap function -> Time Complexity - O(n!*n), Space Complexity - O(1)
class Solution
{
public:
    void permutate(int ind, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            permutate(ind + 1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permutate(0, nums, ans);
        return ans;
    }
};