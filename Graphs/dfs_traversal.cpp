// Practice link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
// Depth First Search Traversal of Graph

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<int> dfsOfGraph(int V, vector<int> adj[]);
void dfsT(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs);

// Main Function
int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfsTraversal;
    dfsTraversal = dfsOfGraph(V, adj);

    for (auto it : dfsTraversal)
    {
        cout << it << " ";
    }

    return 0;
}

// Using Recursion -> Time Complexity - O(V+E), Space Complexity - O(V)
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visitedArray(V, 0);
    vector<int> dfs;

    // Disconnected Graph (Contains Components)
    for (int i = 0; i < V; i++)
    {
        if (!visitedArray[i])
        {
            dfsT(i, visitedArray, adj, dfs);
        }
    }

    return dfs;
}

// Recursive Function
void dfsT(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsT(it, vis, adj, dfs);
        }
    }
}