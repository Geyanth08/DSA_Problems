// Practice link - https://www.codingninjas.com/codestudio/problems/1062670
// Detect Cycle in an Undirected Graph

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool checkCycle(int node, int par, vector<int> &vis, vector<int> adj[]);
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
        adj[v].push_back(u);
    }

    if (isCycle_dfs(V, adj))
    {
        cout << "Cycle is Detected";
    }
    else
    {
        cout << "No Cycle is Detected";
    }

    return 0;
}

// Using BFS Traversal -> Time Complexity - O(V+E), Space Complexity - O(V)
bool isCycle_bfs(int V, vector<int> adj[])
{

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {

            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front().first;
                int par = q.front().second;
                q.pop();

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if (it != par)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

// Using DFS Traversal -> Time Complexity - O(V+E), Space Complexity - O(V)
bool isCycle_dfs(int V, vector<int> adj[])
{

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, -1, vis, adj))
                return true;
        }
    }

    return false;
}

// Recursive Function for DFS Traversal
bool checkCycle(int node, int par, vector<int> &vis, vector<int> adj[])
{

    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, node, vis, adj))
                return true;
        }
        else if (it != par)
        {
            return true;
        }
    }

    return false;
}