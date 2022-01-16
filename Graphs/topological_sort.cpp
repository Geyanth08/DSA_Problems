// Topological Sort of a Directed Acyclic Graph (DAG)

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<int> topoSort_bfs(int V, vector<int> adj[]);
vector<int> topoSort_dfs(int V, vector<int> adj[]);
void topoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]);

// Main function
int main(){

    int V,E;
    cin >> V >> E;

    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> topo_sort;
    topo_sort = topoSort_dfs(V,adj);

    for(auto it : topo_sort){
        cout << it << " ";
    }

    return 0;
}

// Using BFS Traversal (Kahn's Algorithm) -> Time Complexity - O(V+E), Space Complexity - O(V)
vector<int> topoSort_bfs(int V, vector<int> adj[]) {

    queue<int> q;
    vector<int> indegree(V,0);
    
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    for(int i=0;i<V;i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    
    return topo;
}

// Using DFS Traversal -> Time Complexity - O(V+E), Space Complexity - O(V)
vector<int> topoSort_dfs(int V, vector<int> adj[]){
    
    stack<int> st;
    vector<int> vis(V,0);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            topoSort(i,vis,st,adj);
        }
    }

    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

// Recursive function for DFS Traversal
void topoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            topoSort(it,vis,st,adj);
        }
    }

    st.push(node);
}