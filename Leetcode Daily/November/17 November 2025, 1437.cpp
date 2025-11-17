class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        int i = 0, n = nums.size();
        while(i<n && nums[i]!=1)i++;
        i++;
        for(;i<n;i++){
            if(nums[i] == 0){
                count++;
            }
            else {
                if(count<k)return false;
                count=0;
            }
        }
        return true;
    }
};
