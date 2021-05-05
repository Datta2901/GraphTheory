#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1],answer; // one based indexing
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
            answer.push_back(i);
            while(!track.empty()){
                int temp = track.front();
                track.pop();
                // for(int i = 0; i < adj[temp].size(); i++){
                //     if(!visited[i]){
                //         track.push(adj[temp][i]);
                //         answer.push_back(adj[temp][i]);
                //         visited[adj[temp][i]] = true;
                //     }
                // }
                for(auto i : adj[temp]){
                    if
                    track.push(i);
                    answer.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }

    // for(auto i : answer){
    //     cout << i << " ";
    // }
    // cout << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}