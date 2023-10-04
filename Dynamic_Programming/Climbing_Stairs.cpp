#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1,-1);
        return solve(n,stairs);
    }
    int solve(int n,vector<int>& stairs){
        if(n<=1) return 1;
        if(stairs[n]!=-1) return stairs[n];
        return stairs[n] = solve(n-1,stairs) + solve(n-2,stairs);
    }
};

int main() {
    Solution obj;
    cout<<obj.climbStairs(3);
}

