class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);

        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }

        // For each mod class, store minimum prefix seen so far
        vector<long long> best(k, LLONG_MAX);
        best[0] = 0;  // empty prefix

        long long ans = LLONG_MIN;

        for(int i = 1; i <= n; i++) {
            int mod = i % k;

            // If there's a previous prefix with same mod
            if(best[mod] != LLONG_MAX)
                ans = max(ans, pref[i] - best[mod]);

            // Update smallest prefix for this mod
            best[mod] = min(best[mod], pref[i]);
        }

        return ans;
    }
};
