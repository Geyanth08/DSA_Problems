// Leetcode link - https://leetcode.com/problems/kth-largest-element-in-an-array/
// return the kth largest element in the array.

#include <bits/stdc++.h>
using namespace std;

// Using Max heap -> Time Complexity - O(NlogN), Space Complexity - O(N)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq; // Max Heap
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        k -= 1;
        while (k--)
        {
            pq.pop();
        }
        return pq.top();
    }
};