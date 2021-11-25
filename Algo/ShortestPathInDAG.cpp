#include<bits/stdc++.h>
using namespace std;

// idea is to get the topo sort 
//  do bfs on the stack we get 

void dfs(vector<pair<int,int> >adj[],vector<bool>&visited,int source,stack<int>&topo){
    visited[source] = true;
    for(auto it : adj[source]){
        if(!visited[it.first]){
            dfs(adj,visited,it.first,topo);
        }
    }
    topo.push(source);
}

stack<int> topoSort(vector<pair<int,int> >adj[],int vertices){
    vector<bool>visited(vertices,false);
    stack<int>topo;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs(adj,visited,i,topo);
        }
    }
    return topo;
}

void FIndingDistances(vector<pair<int,int> >adj[],vector<int>&distance,int source,stack<int>&topo){
    distance[source] = 0;
    while(!topo.empty()){
        int node = topo.top();
        topo.pop();
        if(distance[node] != INT_MAX){
            for(auto it : adj[node]){
                if(distance[node] + it.second < distance[it.first]){
                    distance[it.first] = distance[node] + it.second;
                }
            }
        }
    }
} 


void printStack(stack<int>a){
    while(!a.empty()){
        cout << a.top() << " ";
        a.pop();
    }
}

int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<pair<int,int> >adj[vertices];
    vector<int>distance(vertices,INT_MAX);
    for(int i = 0; i < edges; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    // for(int i = 0; i < vertices; i++){
    //     cout << i << ": ";
    //     for(auto it : adj[i]){
    //         cout << "{"<<it.first << "," << it.second  << "}";
    //     }
    //     cout << endl;
    // }

    
    stack<int>topo = topoSort(adj,vertices);
    // printStack(topo);
    FIndingDistances(adj,distance,0,topo);
    for(auto i : distance){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
    Sample Input : 
    6 7
    5 0 2
    4 0 2
    4 1 4
    5 2 5
    2 3 6
    3 1 7
    0 5 2
*/