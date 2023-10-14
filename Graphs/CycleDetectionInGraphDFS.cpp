#include<bits/stdc++.h>
using namespace std;

//Cycle detection using BFS
class Graph {
private:
    bool detect(int node, int parent, vector<int> adj[], int vis[]){
        vis[node] = 1;
        for(auto adjacentNode:adj[node]) {
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                if(detect(adjacentNode, node, adj, vis) == true) return true;
            }
            else if(adjacentNode!= parent){
                return true;
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
              if(detect(i, -1, adj, vis) == true) 
                return true;
        }
        return false;
    }
};