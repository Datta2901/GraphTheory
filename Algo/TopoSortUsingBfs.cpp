// Kahn's Algorithm


/*
    1) find inorder of each node.
    2) Push all the elements having inorder 0 to the queue
    3) now perform bfs.
    4) Traversal on its neighbors and reduce inorder for that vertices
    5) If the inorder is 0 then push it to queue
*/

#include<bits/stdc++.h>
using namespace std;



vector<int> bfs(vector<int>adj[],vector<int>indegree,int vertices,queue<int>&track){
    vector<int>answer;
    for(int i = 0; i < vertices; i++){
        while(!track.empty()){
            int node = track.front();
            answer.push_back(node);
            track.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    track.push(it);
                }
            }
        }
    }
    return answer;
}


int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<int>adj[vertices],indegree(vertices,0);
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    queue<int>track;
    int size = indegree.size();
    for(int i = 0; i < size; i++){
        if(indegree[i] == 0){
            track.push(i);
        }
    }
    vector<int>answer = bfs(adj,indegree,vertices,track);
    cout << "Topological sorting of Directed Acyclic Graph is : ";
    for(auto it : answer){
        cout << it  << " ";
    }
}

