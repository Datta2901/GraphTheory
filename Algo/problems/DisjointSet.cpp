// disjointset union by size
#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int>parent,size;
    public:
        DSU(int n){
            for(int i = 0; i < n; i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
        // Path compression make the time complexity O(logn)
        // By using Path COmpression and size the time complexity becomes O(4 * alpha)
        // Here alpha is very very small
        void Union(int u,int v){
            int parU = findParent(u);
            int parV = findParent(v);
            if(parU == parV){
                return ;
            }

            if(size[parU] < size[parV]){
                parent[parU] = parV;
                size[parV] += size[parU];
            }else{
                parent[parV] = parU;
                size[parU] += size[parV];
            }
        }

        int findParent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
};

// disjointset union by Rank


class DSU{
    private:
        vector<int>parent,size;
    public:
        DSU(int n){
            for(int i = 0; i <= n; i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
        void Union(int u,int v){
            int parU = findParent(u);
            int parV = findParent(v);
            if(parU == parV){
                return ;
            }

            if(size[parU] < size[parV]){
                parent[parU] = parV;
                size[parV] += size[parU];
            }else{
                parent[parV] = parU;
                size[parU] += size[parV];
            }
        }

        int findParent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
};
