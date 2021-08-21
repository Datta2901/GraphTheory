/*
    Problem : Find the Shortest path from source to all the nodes present in the graph when the weights are 1 for all edges 
*/
#include<bits/stdc++.h>
using namespace std;

void FindShortestPath(vector<int>adj[],int vertices,int source){
    queue<int>track;
    vector<int>distance(vertices,INT_MAX);//Marking as the highest value
    track.push(source);
    distance[source] = 0;
    while (!track.empty()){
        int node = track.front();
        track.pop();
        for(auto it : adj[node]){
            if(distance[node] + 1 < distance[it]){
                distance[it] = distance[node] + 1;
                track.push(it);
            }
        }
    }
    
    for(auto it : distance){
        cout << it << " ";
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
    }
    int source;
    cin >> source;
    FindShortestPath(adj,vertices,source);
}

