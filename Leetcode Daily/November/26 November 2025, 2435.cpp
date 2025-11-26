class Solution {
public:
    int MOD = 1e9+7;
    int letsgo(int i, int j, vector<vector<int>>&grid, int k, vector<vector<vector<int>>>&dp, int sum, int n, int m){
        if(i>=n ||j>=m)return 0;
        sum+=grid[i][j];
        sum=sum%k;
        if(i == n-1 && j==m-1 && sum%k==0)return 1;
        if(dp[i][j][sum]!=-1)return dp[i][j][sum] % MOD;
        int right = letsgo(i+1,j,grid,k,dp,sum,n,m);
        int down = letsgo(i,j+1,grid, k, dp, sum,n,m);
        return dp[i][j][sum] = (right%MOD+down%MOD)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        int ans=0;
        ans= letsgo(0,0,grid, k, dp, 0, n,m);
        return ans;
    }
};
