#include<bits/stdc++.h>
using namespace std;
// It is used to find the shortest path between the all the pair of vertices
// it can detect the negative cycles
// Distance from same vertice to same vertice is zero.In case of negative cycles we will get negative distances
// In this way it detect the negative cycles

bool FloydWarshall(int vertices, vector<vector<int> > &edges,vector<vector<int> > &distance){
    int e = edges.size();
    // distance from same vertice to same vertice is 0
    for(int i = 0; i < vertices; i++){
        distance[i][i] = 0;
    }

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        distance[u][v] = wt;
    }
    

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            for(int k = 0; k < vertices; k++){
                distance[i][j] = min(distance[i][j],distance[i][k] + distance[k][j]);
            }   
        }
    }

    for(int i = 0; i < vertices; i++){
        if(distance[i][i] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    int e,vertices;
    cin >> vertices >> e;
    vector<vector<int> > edges;
    // Here 100 denotes infinite distance intially
    vector<vector<int> >distance(vertices,vector<int>(vertices,100));
    for(int i = 0; i < e; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    bool answer = FloydWarshall(vertices,edges,distance);
    
    if(!answer){
        cout << "Given Graph has Negative Cycles" << endl;
        return 0;
    }
   
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cout << distance[i][j] << " ";
        }
        cout << endl;
    } 
}
