class Solution {
public:
    int dfs(int i, int j, int k, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(i>=grid.size()|| j>=grid[0].size()){
            return INT_MAX;
        }
        k^=grid[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return k;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k]; 
        
        return dp[i][j][k] = min(dfs(i+1,j,k,grid,dp),dfs(i,j+1,k,grid,dp));
    }
    int minCost(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(2048,-1)));
        return dfs(0,0,0,grid,dp);
    }
};
