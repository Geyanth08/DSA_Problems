// Leetcode link - https://leetcode.com/problems/is-graph-bipartite/
// Check Whether a given graph is Bipartite Graph or not

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool isBipartite_bfs(vector<int> adj[], int V);
bool isBipartite_dfs(vector<int> adj[], int V);
bool checkBipartite(int node, vector<int> adj[], vector<int> &colors);

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

    if (isBipartite_dfs(adj, V))
    {
        cout << "Bipartite Graph";
    }
    else
    {
        cout << "Not a Bipartite Graph";
    }

    return 0;
}

// Using BFS Traversal -> Time Complexity - O(V+E), Space Complexity - O(V)
bool isBipartite_bfs(vector<int> adj[], int V)
{

    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (colors[i] == -1)
        {

            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto it : adj[node])
                {
                    if (colors[it] == -1)
                    {
                        int colorNode = 1 - colors[node];
                        colors[it] = colorNode;
                        q.push(it);
                    }
                    else
                    {
                        if (colors[it] == colors[node])
                            return false;
                    }
                }
            }
        }
    }

    return true;
}

// Using DFS Traversal -> Time Complexity - O(V+E), Space Complexity - O(V)
bool isBipartite_dfs(vector<int> adj[], int V)
{

    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (colors[i] == -1)
        {
            if (!checkBipartite(i, adj, colors))
                return false;
        }
    }

    return true;
}

// Recursive Function DFS Traversal
bool checkBipartite(int node, vector<int> adj[], vector<int> &colors)
{

    if (colors[node] == -1)
        colors[node] = 1;

    for (auto it : adj[node])
    {
        if (colors[it] == -1)
        {
            colors[it] = 1 - colors[node];
            if (!checkBipartite(it, adj, colors))
                return false;
        }
        else if (colors[it] == colors[node])
            return false;
    }

    return true;
}