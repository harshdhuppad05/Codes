class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        for(auto it:queries){
            int idx = it[0];
            while(idx< nums.size() && idx<=it[1]){
                if(idx<nums.size()){
                    long long temp = nums[idx];
                    temp = (temp*it[3])%(1000000007);
                    nums[idx] = temp;
                }
                idx+=it[2];
            }
        }

        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};
