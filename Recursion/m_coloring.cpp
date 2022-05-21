// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
// determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node and graph[k][node] == 1 and color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int n, bool graph[101][101])
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

// Coloring and checking adjacent nodes -> Time Complexity - O(N^M), Space Complexity - O(N)
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    int color[n] = {0};
    if (solve(0, color, m, n, graph))
        return true;
    return false;
}