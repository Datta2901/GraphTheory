/*
    Problem : 
    Given start and end two numbers.And the array of size n
    now find is their a way to multiply any a number in the array any number of times and find 
    we can get end or not.If we can get return minimum number of multiplications else return -1.

*/

// By using bfs

#include<bits/stdc++.h>
using namespace std;

int getMinimumNumberOfOperations(vector<int>nums,int start ,int end){
    vector<bool>visited(end + 1,false);
    int n = nums.size();
    queue<pair<int,int> > track;
    track.push({start,0});
    while(!track.empty()){
        int node = track.front().first;
        int steps= track.front().second;
        track.pop();
        if(node == end){
            return steps;
        }
        for(int i = 0; i < n; i++){
            int dest = node * nums[i];
            if(dest <= end && !visited[dest]){
                track.push({dest,steps + 1});
                visited[dest] = true;
            }
        }
    }
    return -1;
}

int main(){
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int start,end;
    cin >> start >> end;

    return 0;
}