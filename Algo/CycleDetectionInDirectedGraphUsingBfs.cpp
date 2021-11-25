// Kahn's Algorithm


// Idea is to generate topological sort
// if we get topological sort then we can say the graph has no cycle as topological sort only works on DAG(Directed Acyclic Graph)

/*
    For finding Topological sort
    1) find inorder of each node.
    2) Push all the elements having inorder 0 to the queue
    3) now perform bfs.
    4) Traversal on its neighbors and reduce inorder for that vertices
    5) If the inorder is 0 then push it to queue

    6)just check whether topo sort contains all vertices or not
*/

#include<bits/stdc++.h>
using namespace std;



bool bfs(vector<int>adj[],vector<int>indegree,int vertices,queue<int>&track){
    vector<int>answer;
    // no need to store  topo sort as we only want the number of vertices count
    int count = 0;
    for(int i = 0; i < vertices; i++){
        while(!track.empty()){
            int node = track.front();
            answer.push_back(node);
            count++;
            track.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    track.push(it);
                }
            }
        }
    }
    return count == vertices;
    // return answer.size() == vertices;
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
    if(bfs(adj,indegree,vertices,track)){
        cout << "Given graph has no cycle" << endl;
    }else{
        cout << "Given graph has cycle" << endl;
    }
    return 0;  
}

