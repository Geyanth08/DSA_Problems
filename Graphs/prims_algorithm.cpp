// Practice link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Prims Algorithm - Used to find Minimum Spanning Tree (MST)

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<int> prims1(vector<pair<int, int>> adj[], int V);
vector<int> prims2(vector<pair<int, int>> adj[], int V);

// Main Function
int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    vector<int> parent;
    parent = prims2(adj, V);

    for (int i = 1; i < V; i++)
    {
        cout << i << " - " << parent[i] << "\n";
    }

    return 0;
}

// Brute Force Approch -> Time Complexity - O(N^2), Space Complexity - O(N)
vector<int> prims1(vector<pair<int, int>> adj[], int V)
{
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int mini = INT_MAX, u;
        for (int i = 0; i < V; i++)
        {
            if (mstSet[i] == false and key[i] < mini)
                mini = key[i], u = i;
        }

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;

            if (mstSet[v] == false and wt < key[v])
            {
                parent[v] = u, key[v] = wt;
            }
        }
    }

    return parent;
}

// Using priority queue -> Time Complexity - O((V+E)logV), Space Complexity - O(V)
vector<int> prims2(vector<pair<int, int>> adj[], int V)
{
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;

            if (mstSet[v] == false and wt < key[v])
            {
                parent[v] = u;
                key[v] = wt;
                pq.push({key[v], v});
            }
        }
    }

    return parent;
}