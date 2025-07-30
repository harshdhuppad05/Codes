class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = 0;
        int ans = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_val){
                ans =1;
                count = 1;
                max_val = nums[i];
            }
            else if(nums[i] == max_val){
                count++;
                ans = max(ans, count);
            }
            else count = 0;
        }
        return ans;
    }
};
