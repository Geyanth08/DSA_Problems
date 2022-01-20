// Kosaraju's Algorithm - To find strongly connected components

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int kosaraju(int V, vector<int> adj[]);
void dfs(int node,vector<int> &vis, stack<int> &st, vector<int> adj[]);
void revDfs(int node,vector<int> &vis, vector<int> transpose[]);

// Main Function
int main(){

    int V,E;
    cin >> V >> E;

    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    int components = kosaraju(V,adj);
    cout << components;

    return 0;
}

// Using toposort, transpose, dfs traversal -> Time Complexity - O(V+E), Space Complexity - O(V+E)
int kosaraju(int V, vector<int> adj[]){

    stack<int> st;
    vector<int> vis(V,0);
    
    // Topological Sort
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    
    // Transpose the graph
    vector<int> transpose[V];
    for(int i=0;i<V;i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }
    
    // Dfs traversal
    int count = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            count++;
            revDfs(node,vis,transpose);
        }
    }

    return count;
}

// For Topological Sort
void dfs(int node,vector<int> &vis, stack<int> &st, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}

// DFS traversal
void revDfs(int node,vector<int> &vis, vector<int> transpose[]){
    vis[node] = 1;
    for(auto it : transpose[node]){
        if(!vis[it]) revDfs(it,vis,transpose);
    }
}
