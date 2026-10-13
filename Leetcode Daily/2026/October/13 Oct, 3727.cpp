
class Solution {
public:
    static bool cmp(int a, int b) {
        return abs((long long)a) > abs((long long)b);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans += 1LL * nums[i] * nums[i];
            ans -= 1LL * nums[n - 1 - i] * nums[n - 1 - i];
        }

        if (n % 2 == 1) {
            ans += 1LL * nums[n / 2] * nums[n / 2];
        }

        return ans;
    }
};
