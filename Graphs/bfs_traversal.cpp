// Practice link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Breadth First Search Traversal of Graph

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<int> bfsOfGraph(int V, vector<int> adj[]);

// Main Function
int main()
{

    int V, E;
    cin >> V >> E;

    // Creating graph
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Directed Graph
        adj[u].push_back(v);
    }

    vector<int> bfsTraversal;
    bfsTraversal = bfsOfGraph(V, adj);

    for (auto it : bfsTraversal)
    {
        cout << it << " ";
    }

    return 0;
}

// Adding Adjacent nodes to the array -> Time Complexity - O(V+E), Space Complexity - O(V)
vector<int> bfsOfGraph(int V, vector<int> adj[])
{

    vector<int> visitedArray(V, 0);
    vector<int> bfs;

    int i = 0;
    if (!visitedArray[i])
    {
        queue<int> q;
        q.push(i);
        visitedArray[i] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node])
            {
                if (!visitedArray[it])
                {
                    visitedArray[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    // For disconnected graph (when we have multiple components) - use for loop

    return bfs;
}