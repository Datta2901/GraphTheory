//TODO imp : Modified BFS to detect cycle in a graph

#include<bits/stdc++.h>
using namespace std;


bool isThereAcycle(int source,vector<bool>& visited,vector<int> adj[]){
    queue<pair<int,int> > track; // store the current node and its parent (To know from where it came to this node)
    // for the initial node there is no parent so keep some negative number to indicate it
    track.push({source,INT_MIN});
    visited[source] = true;
    while(!track.empty()){
        int currNode = track.front().first;
        int currParent = track.front().second;
        track.pop();
        for(auto i : adj[currNode]){
            if(!visited[i]){
                visited[i] = true;
                track.push({i,currNode});
            }else if(currParent != i){
                return true; // there is a another path to visit this nodes
                // so there is a cycle
            }
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
    bool control = true;
    for(int i = 1; i < vertices; i++) {
        if(!visited[i]){
            if(isThereAcycle(1,visited,adj)){
                control = false;
                cout << "There is a cycle in the given graph " << endl;
                break;
            }
        }
    }


    if(control){
        cout << "There is no cycle in the given graph " << endl;
    }

    //Time complexity of modified BFS will be O(n + E)

    return 0;
}