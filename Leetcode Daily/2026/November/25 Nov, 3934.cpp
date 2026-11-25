
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        const long long BASE = 911382323;
        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;

        vector<long long> h1(n + 1, 0);
        vector<long long> h2(n + 1, 0);

        vector<long long> p1(n + 1, 1);
        vector<long long> p2(n + 1, 1);

        // Step 1: Precompute prefix hashes and powers
        for (int i = 0; i < n; i++) {

            h1[i + 1] = (h1[i] * BASE + nums[i] + 1) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i] + 1) % MOD2;

            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }

        // Step 2: Check whether length len has a unique subarray
        auto check = [&](int len) -> bool {

            unordered_map<unsigned long long, int> freq;

            for (int i = 0; i + len <= n; i++) {

                int j = i + len;

                long long x = (h1[j] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

                long long y = (h2[j] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                // Combine both hashes
                unsigned long long key =
                    (unsigned long long)x * MOD2 + y;

                freq[key]++;
            }

            // Check if any subarray occurs exactly once
            for (auto& [hash, count] : freq) {
                if (count == 1) {
                    return true;
                }
            }

            return false;
        };

        // Step 3: Binary Search
        int low = 1;
        int high = n;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
