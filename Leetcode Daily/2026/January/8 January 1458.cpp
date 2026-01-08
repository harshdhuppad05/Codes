class Solution {
public:
    int f(int i, int j, int n, int m, vector<vector<int>>&dp,vector<int>& nums1, vector<int>& nums2){
        if(i == n || j == m){
            return -1e6;
        }
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int take = nums1[i]* nums2[j] + max(0,f(i+1, j+1, n, m, dp, nums1, nums2));
        int nottake = max(f(i+1,j,n,m,dp,nums1, nums2), f(i, j+1, n, m,dp, nums1, nums2));
        return dp[i][j] = max(take, nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        int ans = f(0,0,n,m,dp,nums1, nums2);
        return ans;
    }
};
