#include<bits/stdc++.h>
using namespace std;

//Cycle detection using BFS
class Graph {
private:
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q; //Store node, parent
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it!= parent) return true;
            }
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V];
        for(int i = 0; i < V; ++i) {
            vis[i] = 0;
        }
        for(int i = 0; i < V; ++i) {
            //If not visited and contains a cycle return true
            if(!vis[i])
              if(detect(i, adj, vis)) 
                return true;
        }
        return false;
    }
};