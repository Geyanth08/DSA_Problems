// Practice link - https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379
// You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

// Using Min Heap -> Time Complexity - O(NlogK), Space Complexity - O(N)
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> index(k, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < k; i++)
        pq.push({kArrays[i][0], i});

    vector<int> sortedArray;
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();

        sortedArray.push_back(temp.first);

        if (index[temp.second] + 1 < kArrays[temp.second].size())
            pq.push({kArrays[temp.second][index[temp.second] + 1], temp.second});

        index[temp.second] += 1;
    }
    return sortedArray;
}
