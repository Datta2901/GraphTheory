#include<bits/stdc++.h>
using namespace std;


//DFS recursive implementation
void DFSRecursive(int curr,vector<bool>& visited,vector<int> adj[],vector<int>& answer){
    answer.push_back(curr);
    visited[curr] = true;
    for(auto it : adj[curr]){
        if(!visited[it]){
            DFSRecursive(it,visited,adj,answer);
        }
    }
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
        adj[v].push_back(u);
    }

    cout << "Adjacency list of given graph is " << endl;
    for(int i = 0; i <= vertices; i++){
        cout << i << " : ";
        for(auto j : adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    int count = 0;

    vector<bool> visited(vertices + 1,false);
    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            DFSRecursive(i,visited,adj,answer);
            count++;
        }
    }

    cout << "The number of connected compotn"

    return 0;
}



