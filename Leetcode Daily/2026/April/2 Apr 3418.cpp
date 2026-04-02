class Solution {
public:
    int dfs(int i, int j, int n, int m,
            vector<vector<vector<int>>>& dp,
            vector<vector<int>>& coins, int count) {

        if(i >= n || j >= m) return -1e9;

        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && count > 0) return 0;
            return coins[i][j];
        }

        if(dp[i][j][count] != -1e9) return dp[i][j][count];

        int ans = -1e9;

        // Take coin
        int take = coins[i][j];
        ans = max(ans, take + dfs(i+1, j, n, m, dp, coins, count));
        ans = max(ans, take + dfs(i, j+1, n, m, dp, coins, count));

        // Skip negative coin
        if(coins[i][j] < 0 && count > 0){
            ans = max(ans, dfs(i+1, j, n, m, dp, coins, count-1));
            ans = max(ans, dfs(i, j+1, n, m, dp, coins, count-1));
        }

        return dp[i][j][count] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(3, -1e9)));

        return dfs(0, 0, n, m, dp, coins, 2);
    }
};
