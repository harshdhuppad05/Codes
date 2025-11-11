class Solution {
public:
    int func(int it, vector<string>& strs, unordered_map<string, pair<int,int>>&mp,int m, int n, vector<vector<vector<int>>>&dp){
        if(it == strs.size()){
            return 0;
        }

        if(dp[it][m][n]!=-1)return dp[it][m][n];
        
        //pick
        int pick = 0, notpick = 0;
        if(m>=mp[strs[it]].first and n>=mp[strs[it]].second){
            pick = 1+func(it+1, strs, mp, m-mp[strs[it]].first, n-mp[strs[it]].second, dp);
        }

        //notpick
        notpick = func(it+1, strs, mp, m, n, dp);

        return dp[it][m][n] = max(pick, notpick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<string, pair<int,int>>mp;
        for(string x: strs){
            int onesc = count(x.begin(), x.end(), '1');
            int zeroc = count(x.begin(), x.end(), '0');
            mp[x] = {zeroc, onesc};
        }
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return func(0, strs, mp, m, n, dp);
    }
};
