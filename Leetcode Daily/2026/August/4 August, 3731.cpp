class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> hash(101,0);
        int mini=101;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            hash[nums[i]]++;
        }
        vector<int>ans;
        for(int i =mini;i<=maxi;i++){
            if(!hash[i])ans.push_back(i);
        }
        return ans;
    }
};
