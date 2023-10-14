#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>, int>> q; // row,col,time
        int vis[m][n];
        int cntFresh = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({{i,j}, time});
                    vis[i][j] = 2;
                }
                else
                    vis[i][j] = 0;
                if(grid[i][j] == 1) cntFresh++;
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            time = max(time,tm);
            int delRow[] = {0, -1, 0, 1};
            int delCol[] = {-1, 0, 1, 0};
            for(int i = 0; i < 4; ++i){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >=0 && nRow <m && nCol>=0 && nCol <n && grid[nRow][nCol] == 1 && vis[nRow][nCol]!=2){
                    vis[nRow][nCol] = 2;
                    q.push({{nRow,nCol}, time+1});
                    cnt++; // Every time visiting/rotting a fresh orange, counting it so that finally it can be compared with the total number of inital fresh oranges
                }
            }
        }
        if(cntFresh != cnt) return -1;
        return time;
    }
};