class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sm=1001,lg=0;
        for(int i=0;i<nums.size();i++){
            sm = min(sm, nums[i]);
            lg=max(lg,nums[i]);
        }
        return gcd(lg, sm);
    }
};
