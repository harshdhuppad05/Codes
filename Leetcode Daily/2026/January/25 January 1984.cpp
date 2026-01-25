class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1e6;
        for(int i=0, j=i+k-1;j<nums.size();i++, j++){
            ans = min(ans, nums[j]-nums[i]);
        }
        return ans;
    }
};
