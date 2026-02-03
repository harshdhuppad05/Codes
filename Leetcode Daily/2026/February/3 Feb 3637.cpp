class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool f2=false, f3=false;
        int n = nums.size();
        int i=1;
        if(nums[0]>=nums[1]){
            return false;
        }
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i>=n-1){
            return false;
        }
        while(i<n-1 && nums[i]>nums[i+1])i++;

        if(i==n-1){
            return false;
        }
        while(i<n-1 && nums[i]<nums[i+1])i++;
        if(i!=n-1){
            return false;
        }
        
        return true;
    }
};
