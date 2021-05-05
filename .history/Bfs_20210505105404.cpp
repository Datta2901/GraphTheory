#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(int )


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

    queue<int> track;

    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            visited[i] = true;
            track.push(i);
            while(!track.empty()){
                int temp = track.front();
                track.pop();
                answer.push_back(temp);
                for(auto i : adj[temp]){
                    if(!visited[i]){
                        track.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }

    cout << "BFS of the given graph is " << endl;
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}



