class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i=0,j=0;
        int n = nums.size();
        int ans = 0,sum = 0;
        while(i<n && j<n){
            if(mp[nums[j]] == 0){
                sum+=nums[j];
                ans = max(ans, sum);
                mp[nums[j]] = 1;
                j++;
            }
            else{
                sum-=nums[i];
                mp[nums[i]] = 0;
                i++;
            }
        }
        return ans;
    }
};
