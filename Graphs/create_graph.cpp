// Create a Graph and print it

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
void adjacent_matrix();
void adjacent_list();

// Main Function
int main()
{

    adjacent_matrix();
    adjacent_list();

    return 0;
}

// Representation of Graph by Adjacency Matrix -> Time Complexity - O(N^2), Space Complexity - O(N^2)
void adjacent_matrix()
{
    int n, m; // n - Number of nodes, m - no of edges
    cin >> n >> m;

    int adj[n][n] = {0};

    // creating graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // For undirected Graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // printing graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

// Representation of Graph by Adjacency List -> Time Complexity - O(n^2(m)), Space Complexity - O(n+2m)
void adjacent_list()
{

    int n, m; // n - Number of nodes, m - no of edges
    cin >> n >> m;

    // creating graph
    vector<int> G[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // For undirected graph
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // printing graph
    for (int i = 0; i < n; i++)
    {
        cout << "vertex " << i;
        for (auto j : G[i])
        {
            cout << " -> " << j;
        }
        cout << "\n";
    }
}