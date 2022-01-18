// Dijsktra Algorithm - To find shortest path between any two vertices of a Unweightes Undirected Graph

#include <bits/stdc++.h>
using namespace std;

// Main Function
int main(){

    int V,E;
    cin >> V >> E;

    vector<pair<int,int>> adj[V];
    int u,v,wt;

    for(int i=0;i<E;i++){
        cin >> u >> v >> wt;

        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }

    int source;
    cin >> source;

    // Dijsktra Algorithm (Using Priority Queue) -> Time Complexity - O(V + ElogV), Space Complexity - O(V)
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // In pair - { distance, from}
    vector<int> dis(V,INT_MAX);

    dis[source] = 0;
    pq.push(make_pair(0,source)); // { distance, from }

    while(!pq.empty()){
        int distance = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for(auto it : adj[prev]){
            int next = it.first;
            int nextDistance = it.second;

            if(dis[next] > dis[prev] + nextDistance){
                dis[next] = dis[prev] + nextDistance;
                pq.push(make_pair(dis[prev],next));
            }
        }
    }

    cout << "The Distances from Source " << source << " are : ";
    for(auto it : dis){
        cout << it << " ";
    }cout << "\n";

    return 0;
}