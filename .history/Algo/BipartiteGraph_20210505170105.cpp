#include<bits/stdc++.h>
using namespace std;

bool bfs(int source,int vertices,vector<int> adj[]){
    vector<int> colors(vertices + 1, -1);
    vector<bool> visited(vertices + 1,false);
    queue<int> track;
    for(int i = 1; i <= vertices; i++){
        track.push(i);
        visited[i] = true;
        colors[i] = 1
        while(!track.empty()){

        }

    }
    return true;
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

    bfs(1, vertices,adj);

    return 0;
}