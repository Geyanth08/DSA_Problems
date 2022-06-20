// Practice link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Kruksal's Algorithm - Used to find Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

// Node Declaration
struct Node
{
    int u, v, wt;

    Node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

// Function Declaration
bool comp(Node a, Node b);
int findParent(int u, vector<int> &par);
void unionn(int u, int v, vector<int> &par, vector<int> &rank);

// Main Function
int main()
{

    int V, E;
    cin >> V >> E;

    vector<Node> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Node(u, v, wt));
    }

    // Kruksal Algorithm (Using disjoint set) -> Time Complexity - O((V+E)logV), Space Complexity - O(V)
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(V);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    vector<int> rank(V, 0);
    vector<pair<int, int>> mst;
    int cost = 0;

    for (auto it : edges)
    {
        if (findParent(it.v, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    cout << cost << endl;

    for (auto it : mst)
    {
        cout << it.first << "-" << it.second << endl;
    }

    return 0;
}

bool comp(Node a, Node b)
{
    return a.wt < b.wt;
}

int findParent(int u, vector<int> &par)
{
    if (u == par[u])
        return u;
    return findParent(par[u], par);
}

void unionn(int u, int v, vector<int> &par, vector<int> &rank)
{
    u = findParent(u, par);
    v = findParent(v, par);

    if (rank[u] < rank[v])
        par[u] = v;
    else if (rank[v] < rank[u])
        par[v] = u;
    else
    {
        par[v] = u;
        rank[u]++;
    }
}