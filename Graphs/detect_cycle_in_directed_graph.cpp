// Practice link - https://www.codingninjas.com/codestudio/problems/1062626
// Detect Cycle in an Directed Graph

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool checkCycle(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfsVis);
bool isCycle_bfs(int V, vector<int> adj[]);
bool isCycle_dfs(int V, vector<int> adj[]);

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

        adj[u].push_back(v);
    }

    if (isCycle_bfs(V, adj))
    {
        cout << "Cycle is Detected";
    }
    else
    {
        cout << "No Cycle is Detected";
    }

    return 0;
}

// Using DFS Traversal -> Time Complexity - O(V+E), Space Complexity - O(V)
bool isCycle_dfs(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, vis, adj, dfsVis))
                return true;
        }
    }

    return false;
}

// Recursive Function for DFS Traversal
bool checkCycle(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, vis, adj, dfsVis))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }

    dfsVis[node] = 0;
    return false;
}

// Using Kahn's Algorithm (BFS Traversal) -> Time Complexity - O(V+E), Space Complexity - O(V)
bool isCycle_bfs(int V, vector<int> adj[])
{

    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    if (count == V)
        return false;
    return true;
}