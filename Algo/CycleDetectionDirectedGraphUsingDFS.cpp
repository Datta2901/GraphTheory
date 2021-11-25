/*
    problem : Cycle detection for directed graph using dfs
*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsVis){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]){
            if(dfs(i,adj,vis,dfsVis)){
                return true; // contains any cycle
            }
        }else if(dfsVis[i]){
            //visited from again the same node without completing this dfs call
            // so it has a cycle 
            return true;
        }
    }
    dfsVis[node] = 0;//After completion of a dfs call making this as 0
    return false;
}

bool checkCycle(vector<int> adj[],int vertices){
    vector<int> vis(vertices + 1,0),dfsVis(vertices + 1,0);
    for(int i = 0; i < vertices; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,dfsVis)){
                return true;
            }
        }
    }

    return false;
}
 

int main(){
    int vertices,edges;
    cout << "Enter the vertices and edges of the graph respectively " << endl;
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1],answer; // one based indexing
    cout << "Enter the edges of the graph" << endl;
    for(int i = 1; i <= edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u); gieven a directed Graph
    }

    cout << "Adjacency list of given graph is " << endl;
    for(int i = 0; i <= vertices; i++){
        cout << i << " : ";
        for(auto j : adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    if(checkCycle(adj,vertices)){
        cout << "Given directed graph as a cycle\n";
    }else{
        cout << "Given directed graph not have a cycle\n";
    }
    
    return 0;
}

/*
    time complexity : O(N + E)
    space complexity : O(N + E) +  O(N)  +  O(N)
                        adj        visited    dfsVis 
*/