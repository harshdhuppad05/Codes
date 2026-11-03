class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums.size()-1;
        int ans = 0;
        for(auto it:nums){
            ans+=abs(it-nums[mid]);
        }
        return ans;
    }
};
