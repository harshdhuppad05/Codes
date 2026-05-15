class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        if(nums[i]<nums[j])return nums[i];
        while(i<j){
            int mid=i+(j-i)/2;
            // cout<<mid;
            if(nums[mid]>=nums[i] && nums[mid]>nums[j])i=mid+1;
            else if(nums[mid]>nums[i] && nums[mid]<nums[j])return nums[i];
            else if(nums[mid]<nums[j])j=mid;
        }
        return nums[i];
    }
};
