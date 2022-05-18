// Leetcode link - https://leetcode.com/problems/combination-sum/submissions/
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
// We can choose a number UNLIMITED times

#include <bits/stdc++.h>
using namespace std;

// Every element has n number of choices -> Time Complexity - O(2^t*K), Space Complexity - O(2^N)
class Solution
{
public:
    void func(int ind, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (candidates.size() == ind)
        {
            if (target == 0)
                ans.push_back(ds);
            return;
        }
        // Pick up the element
        if (candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            func(ind, target - candidates[ind], candidates, ds, ans);
            ds.pop_back();
        }
        // Not Pick up the element
        func(ind + 1, target, candidates, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, target, candidates, ds, ans);
        return ans;
    }
};
