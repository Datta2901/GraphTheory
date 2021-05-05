#include<bits/stdc++.h>
using namespace std;



// Dfs for the indexing one with more time complexity
// And works for any graph 
vector<int> DFS(int vertices,vector<int> adj[]){
    vector<int>answer;
    vector<bool> visited(vertices + 1,false);
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
    return answer;
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

    answer = bfs(vertices,adj);
    
    cout << "BFS of the given graph is " << endl;
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;

    answer = bfsOfGraph(vertices,adj);
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}



