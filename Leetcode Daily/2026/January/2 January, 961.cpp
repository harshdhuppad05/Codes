class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[0] || nums[i] == nums[nums.size()-1] || nums[i] == nums[i-1])return nums[i];
        }
        return -1;
    }
};
