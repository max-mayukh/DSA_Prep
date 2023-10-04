#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs (vector<int> adj[], vector<int>& ls, int node, int vis[]){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(adj, ls, it, vis);
            }
        }
    }  
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ls;
        int vis[V] = {0};
        vis[0] = 1;
        int start = 0;
        
        dfs(adj, ls, start, vis);
        return ls;
    }
};

int main() {
    return 0;
}