// Practice link - https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322
// You are given two arrays/lists ‘A’ and ‘B’ of size ‘N’ each. You are also given an integer ‘K’. You have to find the ‘K’ maximum and valid sum combinations from all the possible sum combinations of the arrays/lists ‘A’ and ‘B’.

#include <bits/stdc++.h>
using namespace std;

// Using sorting, max heap and set -> Time Complexity - O(NlogN), Space Complexity - O(N)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<pair<int, pair<int, int>>> pq; // {sum,{i,j}}
    set<pair<int, int>> s;
    vector<int> combinations;

    pq.push(make_pair(a[n - 1] + b[n - 1], make_pair(n - 1, n - 1)));
    s.insert(make_pair(n - 1, n - 1));

    for (int count = 0; count < k; count++)
    {
        auto temp = pq.top();
        pq.pop();

        combinations.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = a[i - 1] + b[j];
        auto temp1 = make_pair(i - 1, j);
        if (s.find(temp1) == s.end())
        {
            pq.push(make_pair(sum, temp1));
            s.insert(temp1);
        }

        sum = a[i] + b[j - 1];
        auto temp2 = make_pair(i, j - 1);
        if (s.find(temp2) == s.end())
        {
            pq.push(make_pair(sum, temp2));
            s.insert(temp2);
        }
    }

    return combinations;
}