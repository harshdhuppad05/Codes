class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int zero_count=0;
        for(int i:nums){
            sum^=i;
            zero_count+=i==0?1:0;
        }
        if(zero_count==n)return 0;
        return n-(sum==0);
    }
};
