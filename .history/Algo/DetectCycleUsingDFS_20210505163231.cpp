#include<bits/stdc++.h>
using namespace std;

bool isThereAcycle(int source,int parent,vector<bool>& visited,vector<int> adj[]){
   visited[source] = true;
    for(auto i : adj[source]){
        if(!visited[i]){
            if(isThereAcycle(i,source,visited,adj)){
                return true;
            }
        }else if(i != parent){
            return true;
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

    vector<bool> visited(vertices + 1,false);
    booflag = false;
    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            if(isThereAcycle(i,-1,visited,adj)){

            }
        }
    }

    /* 
        Time complexity of BFS will be O(n + E)
        Time for visiting n nodes and e for visiting adjacent nodes in Adjacency list
    */
    return 0;

}