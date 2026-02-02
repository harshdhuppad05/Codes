class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long base = nums[0];

        // multiset for k-1 smallest elements
        multiset<int> small, large;
        long long smallSum = 0;

        auto balance = [&]() {
            while ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                smallSum -= *it;
                large.insert(*it);
                small.erase(it);
            }
            while ((int)small.size() < k - 1 && !large.empty()) {
                auto it = large.begin();
                smallSum += *it;
                small.insert(*it);
                large.erase(it);
            }
        };

        long long ans = LLONG_MAX;
        int r = 1;

        for (int l = 1; l < n; l++) {
            // Expand window
            while (r < n && r <= l + dist) {
                if (small.empty() || nums[r] <= *prev(small.end())) {
                    small.insert(nums[r]);
                    smallSum += nums[r];
                } else {
                    large.insert(nums[r]);
                }
                balance();
                r++;
            }

            // If we have k-1 elements, update answer
            if ((int)small.size() == k - 1) {
                ans = min(ans, base + smallSum);
            }

            // Remove l-th element
            if (small.find(nums[l]) != small.end()) {
                smallSum -= nums[l];
                small.erase(small.find(nums[l]));
            } else {
                large.erase(large.find(nums[l]));
            }
            balance();
        }

        return ans;
    }
};
