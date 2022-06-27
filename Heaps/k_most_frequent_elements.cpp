// Practice link - https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808
// You are given an Integer array ‘ARR’ and an Integer ‘K’. Your task is to find the ‘K’ most frequent elements in ‘ARR’. Return the elements sorted in ascending order

#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

// Using Hashing and MaxHeap -> Time Complexity - O(KlogN), Space Complexity - O(K)
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
        um[arr[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq(um.begin(), um.end());

    vector<int> kFrequent;
    for (int i = 0; i < k; i++)
    {
        kFrequent.push_back(pq.top().first);
        pq.pop();
    }
    sort(kFrequent.begin(), kFrequent.end());
    return kFrequent;
}