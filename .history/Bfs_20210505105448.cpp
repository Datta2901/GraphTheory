#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(int vertices,vector<int> adj[]){
    vector<int>answer;

    return answer;
}


int main(){
    int vertices,edges;
    cout << "Enter the vertices and edges of the graph respectively " << endl;
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1],answer; // one based indexing
    vector<bool> visited(vertices + 1,false);
    cout << "Enter the edges of the graph" << endl;
    for(int i = 1; i <= edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   

    cout << "BFS of the given graph is " << endl;
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}



