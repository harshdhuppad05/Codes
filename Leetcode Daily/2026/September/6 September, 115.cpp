class Solution {
public:

    int totalDistinct(int i, int j, string s, string t,vector<vector<int>>&dp){
        if(j <0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = totalDistinct(i-1,j-1,s,t,dp) + totalDistinct(i-1,j,s,t,dp); 
        }
        return dp[i][j] = totalDistinct(i-1,j,s,t,dp);
    }

    int numDistinct(string s, string t) {
        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return totalDistinct(n-1, m-1,s,t,dp);
        //we use unsigned int because there is a case with a quite large data
        vector<vector<unsigned int>> dp(t.size() + 1, vector<unsigned int>(s.size() + 1));
        
		//set as default value of  the first line as 1
        for (int j = 0; j <= s.size(); j++)dp[0][j] = 1;

        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {

					if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
