class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();
        int i=1,j=n-2;
        int ans = n;
        if(nums[0]!=nums[n-1])return n-1;
        // if(nums[0]!=nums[n-1])return n-1;
        while(i<=j && nums[i]== nums[j]){
            if(nums[i]!=nums[i-1])return n-i-1;
            else if(nums[j]!=nums[j+1])return j-1;
            i++;
            j--;
        }
        return n-i-1;
    }
};      
