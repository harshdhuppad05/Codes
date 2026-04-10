class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it:mp){
            vector<int>arr = it.second;
            int m = arr.size();
            for(int i=2;i<m;i++){
                int dist = 2*(arr[i]-arr[i-2]);
                ans=min(ans, dist);
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};
