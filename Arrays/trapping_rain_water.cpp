// Leetcode link - https://leetcode.com/problems/trapping-rain-water/
// Given Elevation map (set of heights), Find how much water can be trapped

#include <bits/stdc++.h>
using namespace std;

// Using Two Pointer Approach -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int left = 0, right = n - 1;
        int trapped_water = 0;
        int maxLeft = 0, maxRight = 0;

        while (left <= right)
        {
            if (height[left] <= height[right])
            {

                if (height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    trapped_water += maxLeft - height[left];

                left++;
            }
            else
            {

                if (height[right] >= maxRight)
                    maxRight = height[right];
                else
                    trapped_water += maxRight - height[right];

                right--;
            }
        }

        return trapped_water;
    }
};