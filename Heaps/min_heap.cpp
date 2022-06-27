// Practice link - https://www.codingninjas.com/codestudio/problems/min-heap_4691801
// Implement min heap

#include <bits/stdc++.h>
using namespace std;

// Using STL
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v;
    for (auto it : q)
    {
        if (it[0] == 0)
            pq.push(it[1]);
        else
        {
            v.push_back(pq.top());
            pq.pop();
        }
    }
    return v;
}
