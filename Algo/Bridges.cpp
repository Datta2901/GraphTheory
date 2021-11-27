// Tarjan's Algorithm

// Approach :

// Mark intime of each node in dfs
// And then keep track of lowest time possible among the adjacent nodes
// if we find a node is having the least time than the current node while traversing back in dfs
// then it is a bridge


// If there is a cycle no edge is a bridge inside that component
// If there is no cycle in a componenent then every edge is a bridge

// If two or more cycles connected in a graph then the connecting edge is a bridge

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<int>&tin,vector<int>&low,vector<bool>&visited,int node,int parent,int &timer){
    visited[node] = true;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for(auto it : adj[node]){
        if(parent == it){
            continue;
        }
        if(!visited[it]){
            dfs(adj,tin,low,visited,it,node,timer);
            low[node] = min(low[node],low[it]);
            if(low[it] > tin[node]){
                cout << node << " " << it << endl;
            }
        }else{
            low[node] = min(low[node],tin[it]);
        }
    }
}

int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<int>adj[vertices + 1];
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>tin(vertices,-1),low(vertices,-1);
    vector<bool>visited(vertices,false);
    int timer = 0;
    cout << "Bridges are : " << endl;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs(adj,tin,low,visited,i,-1,timer);
        }
    }

}

