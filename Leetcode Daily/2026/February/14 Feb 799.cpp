class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100,0));
        dp[0][0] = poured;
        for(int i = 1;i<100;i++){
            for(int j = 0;j<=i;j++){
                if(dp[i-1][j]>1)dp[i][j] += (dp[i-1][j]-1)/2;
                if(j!=0 && dp[i-1][j-1]>1)dp[i][j] += (dp[i-1][j-1]-1)/2;
            }
        }
        if(dp[query_row][query_glass]>1)return 1.00000;
        else return dp[query_row][query_glass];
    }
};
