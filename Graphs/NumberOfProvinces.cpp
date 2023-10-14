#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count = 0;
    void dfs(vector<vector<int>>& isConnected, int node, vector<int>& vis){
        for(int i = 0; i < isConnected.size(); ++i){
            if(isConnected[node][i] && !vis[i]){
                vis[i] = 1;
                dfs(isConnected, i, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // int vis[n] = {0};
        vector<int> vis(n,0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j] && !vis[i]){
                    vis[i] = 1;
                    count++;
                    dfs(isConnected, i, vis);
                }
            }
        }
        return count;
    }
};