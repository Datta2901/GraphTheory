#include<bits/stdc++.h>
using namespace std;

bool bfs(int source,int vertices,vector<int> adj[]){
    queue<int> track;
    track.push(s)
    int node;
    if(colors[i] != -1){
        track.push(i);
        colors[i] = 1 - colors[node];
        while(!track.empty()){
            node = track.front();
            track.pop();
            for(auto i : adj[node]){
            }    
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

    vector<int> colors(vertices + 1, -1);

    for(int i = 1; i <= vertices; i++){

    }

    return 0;
}