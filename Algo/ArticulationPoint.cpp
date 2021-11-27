// Tarjan's Algorithm

// Approach :

// Mark intime of each node in dfs
// And then keep track of lowest time possible among the adjacent nodes
// if we find a node is having the least time than the current node while traversing back in dfs
// then it is a bridge


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<int>&tin,vector<int>&low,vector<bool>&visited,int node,int parent,int &timer,vector<bool>&articulationPoints){
    visited[node] = true;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for(auto it : adj[node]){
        if(parent == it){
            continue;
        }
        if(!visited[it]){
            dfs(adj,tin,low,visited,it,node,timer,articulationPoints);
            low[node] = min(low[node],low[it]);
            child++;
            if(low[it] >= tin[node] && parent != -1){
                articulationPoints[node] = 1;
            }
        }else{
            low[node] = min(low[node],tin[it]);
        }
    }
    if(parent == -1 && child > 1){
        articulationPoints[node] = true;
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
    vector<bool>visited(vertices,false),articulationPoints(vertices,false);
    int timer = 0;
    cout << "Articulation points are : " << endl;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs(adj,tin,low,visited,i,-1,timer,articulationPoints);
        }
    }

    for(int i = 0; i < vertices; i++){
        if(articulationPoints[i]){
            cout << i << " ";
        }
    }
    cout << endl;

}

