class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto num:nums){
            if(num%2==0)ans.push_back(-1);
            else {
                ans.push_back(num - ((num + 1) & (-num - 1)) / 2);
            }
        }
        return ans;
    }
};          
