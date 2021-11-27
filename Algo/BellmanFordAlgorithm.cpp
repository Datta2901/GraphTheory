// It is also used to find the shortest path between sources to all other vertices when we are having negative weights

// Dijkstra algorithm fails when we have negative edge cycles.It will be remain in that cycle by keep on decreasing the distance
// so we use bellman ford algorithm in this case. 
// We have vertices - 1 relaxation in this 
// we will update the distances in each relaxation
// Belman ford algo applied on directed graph
// If we want to apply on undirected graph then we have to convert it to directed graph


#include<bits/stdc++.h>
using namespace std;

bool BellMannFord(int vertices, vector<tuple<int,int,int>> edges,vector<int>&distance){
    int e = edges.size();
    // n - 1 relaxation to get the sortest distance from source to all other
    for(int i = 1; i <= vertices - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            int u = get<0>(edges[j]);
            int v = get<1>(edges[j]);
            int wt = get<2>(edges[j]);
            if(distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }
    // Another relaxation to detect negative cycle if any
    // If still the distance is decreasing then it has negative cycle

    for(int j = 0; j < edges.size(); j++){
        int u = get<0>(edges[j]);
        int v = get<1>(edges[j]);
        int wt = get<2>(edges[j]);
        if(distance[u] + wt < distance[v]){
            return false;
        }
    }
    return true;
}

int main(){
    int e,vertices;
    cin >> vertices >> e;
    vector<tuple<int,int,int>> edges;
    vector<int>distance(vertices,100);
    for(int i = 0; i < e; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(tuple<int,int,int>{u,v,wt});
    }
    distance[0] = 0;
    bool answer = BellMannFord(vertices,edges,distance);
    if(answer){
        for(int i = 0; i < vertices; i++){
            cout << distance[i] << " ";
        } 
    }else{
        cout << "Given Graph has negative cycle" << endl;
    }
}
