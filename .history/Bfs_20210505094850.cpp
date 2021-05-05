#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1]; // one based indexing
    vector<int> visited(vertices + 1,0);
    for(int i = 1; i <= edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= vertices; i++){
        if(!visited)
    }

    return 0;
}