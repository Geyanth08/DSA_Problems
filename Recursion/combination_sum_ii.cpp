// Leetcode link - https://leetcode.com/problems/combination-sum-ii/submissions/
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination and no duplicates

#include <bits/stdc++.h>
using namespace std;

// Sort and avoid picking duplicants -> Time Complexity - O(2^K*N), Space Copmlexity - O(K*X)
class Solution
{
public:
    void func(int ind, int target, vector<int> &arr, vector<int> ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind and arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            func(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        func(0, target, candidates, ds, ans);
        return ans;
    }
};