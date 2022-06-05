// Leetcode link - https://leetcode.com/problems/next-greater-element-i/
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// Return an array ans of length nums1.length such that ans[i] is the next greater element.

#include <bits/stdc++.h>
using namespace std;

// Traversing nums2 array from back -> Time COmplexity - O(N+M), Space Complexity - O(N)
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        map<int, int> m;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!s.empty() and nums2[i] >= s.top())
                s.pop();
            if (!s.empty())
                m[nums2[i]] = s.top();
            else
                m[nums2[i]] = -1;
            s.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};