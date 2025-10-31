class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        int a=-1,b=-1;
        mp[nums[0]]++;
        for(int i = 1;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(a!=-1)b = nums[i];
                else a= nums[i];
            }
            mp[nums[i]]++;
        }
        return {a,b};
    }
};
