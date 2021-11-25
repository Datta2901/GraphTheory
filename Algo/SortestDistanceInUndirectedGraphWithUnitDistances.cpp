#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],vector<int>&distance,int source){
    queue<int>track;
    track.push(source);
    distance[source] = 0;
    while(!track.empty()){
        int node = track.front();
        track.pop();
        for(auto it : adj[node]){
            if(distance[it] == INT_MAX){ // or if(distance[node] + 1 < distance[it])
                distance[it] = distance[node] + 1;
                track.push(it);
            }
        }
    }
} 


int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<int>adj[vertices],distance(vertices,INT_MAX);
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(adj,distance,0);

    for(auto i : distance){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

