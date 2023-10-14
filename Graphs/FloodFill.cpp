#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int visited[m][n];
    int targetColor = image[sr][sc];
    queue<pair<int,int>> q;
    q.push({sr,sc});
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            visited[i][j] = 0;
        }
    }
    visited[sr][sc] = 1;
    image[sr][sc] = color;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int delrow[] = {0,-1,0,+1};
        int delcol[] = {-1, 0, +1, 0};
        for(int i = 0; i < 4; ++i){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow < m && ncol>=0 && ncol<n && image[nrow][ncol] == targetColor &&
            visited[nrow][ncol] == 0){
                visited[nrow][ncol] = 1;
                image[nrow][ncol] = color;
                q.push({nrow,ncol});
            }
        }
    }
    return image;
    }
};