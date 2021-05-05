#include<bits/stdc++.h>
using namespace std;



// DFS iterative implementation 
vector<int> DFS(int vertices,vector<int> adj[]){
    vector<int>answer;
    vector<bool> visited(vertices + 1,false);
    stack<int> track;
    
    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            visited[i] = true;
            track.push(i);
            while(!track.empty()){
                int temp = track.top();
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

//DFS recursive implementation

vector<int> DFSRecursive(int curr,vector<int>  vector<int> adj[]){
    vector<int> answer;
    
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


    answer = DFS(vertices,adj);
    
    cout << "DFS of the given graph is " << endl;
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;

    cout << "------------------------------------" << endl;
    cout << "DFS recursive implementation " << endl;
    
    vector<bool> visited(vertices + 1,false);
    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            DFSRecursive(i,visited,adj);
        }
    }

    return 0;
}



