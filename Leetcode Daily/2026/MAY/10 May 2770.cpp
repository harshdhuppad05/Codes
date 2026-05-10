class Solution {
public:

    int jumps(int i, int j, vector<int> &nums, int target, vector<vector<int>>&dp,bool flag){
        if(j == nums.size() && flag == true)return 0;
        if(j == nums.size() && flag == false)return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        int take = INT_MIN;
        int nottake = jumps(i,j+1,nums,target,dp,false);
        if(abs(nums[i]-nums[j])<=target){
            take = 1+jumps(j,j+1,nums,target,dp,true);
        }
        return dp[i][j] = max(take, nottake);
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        if(jumps(0,1,nums,target,dp,true) <= 0 )return -1;
        return jumps(0,1,nums,target,dp,true);
    }
};
