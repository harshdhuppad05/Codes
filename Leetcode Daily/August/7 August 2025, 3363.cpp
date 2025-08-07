class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans = 0;
        for(int i = 0;i<fruits.size();i++){
            ans+=fruits[i][i];
            fruits[i][i] = 0;
        }
        int n = fruits.size();
        for(int i = 1;i<fruits.size();i++){
            for(int j = 0;j<i;j++){
                if(i<n-1-j){
                    fruits[i][j] = 0;
                }
            }
        }
        for(int j = 1;j<fruits.size();j++){
            for(int i = 0;i<j;i++){
                if(j<n-1-i){
                    fruits[i][j] = 0;
                }
            }
        }
        // for(int i = 0;i<fruits.size();i++){
        //     for(int j = 0;j<fruits.size();j++){
        //         cout<<fruits[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        ans+=find1(n-1,0,n,dp1,fruits);
        ans+=find2(0,n-1,n,dp2,fruits);
        return ans;
    }
    int find1(int i, int j, int n, vector<vector<int>>&dp1, vector<vector<int>>&fruits){
        if(i==n-1 && j==n-1)return 0;
        if (j >= i)
            return 0;
        if (dp1[i][j] != -1)
            return dp1[i][j];
        int res = 0;
        int curr = fruits[i][j];
        if (i - 1 >= 0)
            res = max(res, curr + find1(i - 1, j + 1,n,dp1,fruits));
        res = max(res, curr + find1(i, j + 1,n,dp1,fruits));
        if (i + 1 < n)
            res = max(res, curr + find1(i + 1, j + 1,n,dp1,fruits));
        dp1[i][j] = res;
        return res;
    }
    int find2(int i, int j, int n, vector<vector<int>>&dp2, vector<vector<int>>&fruits){
        if(i==n-1 && j==n-1)return 0;
        if (i >= j)
            return 0;
        if (dp2[i][j] != -1)
            return dp2[i][j];
        int res = 0;
        int curr = fruits[i][j];
        if (j - 1 >= 0)
            res = max(res, curr + find2(i + 1, j - 1,n,dp2,fruits));
        res = max(res, curr + find2(i+1, j ,n,dp2,fruits));
        if (j + 1 < n)
            res = max(res, curr + find2(i + 1, j + 1,n,dp2,fruits));
        dp2[i][j] = res;
        return res;
    }
};
