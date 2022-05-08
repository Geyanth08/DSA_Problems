// Leetcode link - https://leetcode.com/problems/majority-element-ii/
// Find all majority elements of the array (i.e., elements that occur more than n/3 times)

#include <bits/stdc++.h>
using namespace std;

// Using Boyer Moore's Voting Algorithm -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
            {
                c1++;
            }
            else if (nums[i] == num2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                num1 = nums[i];
                c1++;
            }
            else if (c2 == 0)
            {
                num2 = nums[i];
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        vector<int> ans;
        c1 = c2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
            {
                c1++;
            }
            else if (nums[i] == num2)
            {
                c2++;
            }
        }

        if (c1 > nums.size() / 3)
        {
            ans.push_back(num1);
        }
        if (c2 > nums.size() / 3)
        {
            ans.push_back(num2);
        }

        return ans;
    }
};