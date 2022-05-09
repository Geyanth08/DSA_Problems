// Leetcode link - https://leetcode.com/problems/4sum/
// Given an array, return all possible unique quadruplets (a+b+c+d = target)

#include <bits/stdc++.h>
using namespace std;

// Fix Two pointers and iterate another two pointers -> Time Complexity - O(N^3), Space Complexity - O(1)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target_4)
    {
        vector<vector<int>> res;

        if (nums.empty())
            return res;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int target_3 = target_4 - nums[i];

            for (int j = i + 1; j < n; j++)
            {
                int target_2 = target_3 - nums[j];

                int front = j + 1;
                int back = n - 1;

                while (front < back)
                {
                    int two_sum = nums[front] + nums[back];

                    if (two_sum < target_2)
                        front++;
                    else if (two_sum > target_2)
                        back--;
                    else
                    {

                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];

                        res.push_back(quad);

                        while (front < back and nums[front] == quad[2])
                            ++front;
                        while (front < back and nums[back] == quad[3])
                            --back;
                    }
                }
                while (j + 1 < n and nums[j + 1] == nums[j])
                    ++j;
            }
            while (i + 1 < n and nums[i + 1] == nums[i])
                ++i;
        }

        return res;
    }
};