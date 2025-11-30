class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = 1e5+1;
        int n = nums.size();
        long long total_sum = accumulate(nums.begin(), nums.end(), 0ll);
        if(total_sum < p)return -1;
        int need_to_remove = total_sum%p;
        if(need_to_remove == 0)return 0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        int curr = 0;
        for(int i = 0;i<n;i++){
            curr = (nums[i]+curr)%p;
            mp[curr] = i;
            int to_find = (curr - need_to_remove + p)%p;
            if(mp.find(to_find)!=mp.end())ans = min(ans, i-mp[to_find]);
        }
        return ans >= n?-1:ans;
    }
};
