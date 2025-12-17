class Solution {
public:
    long long INF = 1e14;

    long long max_profit(int i, int state, vector<int>& prices,
                         int k, int n,
                         vector<vector<vector<long long>>>& dp) {

        if (i == n) {
            return (state == 0 ? 0 : -INF);
        }

        if (dp[i][k][state] != -INF)
            return dp[i][k][state];

        long long ans = -INF;

        // Do nothing
        ans = max(ans, max_profit(i+1, state, prices, k, n, dp));

        if (state == 0) {
            // start long
            ans = max(ans, -prices[i] + max_profit(i+1, 1, prices, k, n, dp));
            // start short
            ans = max(ans,  prices[i] + max_profit(i+1, 2, prices, k, n, dp));
        }
        else if (state == 1 && k > 0) {
            // sell (close long)
            ans = max(ans, prices[i] + max_profit(i+1, 0, prices, k-1, n, dp));
        }
        else if (state == 2 && k > 0) {
            // buy back (close short)
            ans = max(ans, -prices[i] + max_profit(i+1, 0, prices, k-1, n, dp));
        }

        return dp[i][k][state] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k+1, vector<long long>(3, -INF))
        );
        return max_profit(0, 0, prices, k, n, dp);
    }
};
