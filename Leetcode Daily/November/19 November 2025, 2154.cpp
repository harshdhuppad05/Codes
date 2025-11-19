class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        while(true){
            if(mp.find(original)!=mp.end()){
                original*=2;
            }
            else break;
        }
        return original;
    }
};
