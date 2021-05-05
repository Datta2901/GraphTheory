#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1]; // one based indexing
    vector<bool> visited(vertices + 1,false);
    for(int i = 1; i <= edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            visited[i] = true;
            queue<int> track;
            track.push(i);
            while(!track.empty()){
                int temp = track.front();
                track.pop();
                for(auto )
            }
        }
    }

    return 0;
}