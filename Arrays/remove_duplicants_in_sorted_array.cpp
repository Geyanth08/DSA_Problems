// Leetcode link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Find number of unique elements in the array and bring all unique elements to front

#include <bits/stdc++.h>
using namespace std;

// Using Two pointer approach -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int i = 0;

        for (int k = 1; k < nums.size(); k++)
        {
            if (nums[i] != nums[k])
            {
                i++;
                nums[i] = nums[k];
            }
        }

        return i + 1;
    }
};