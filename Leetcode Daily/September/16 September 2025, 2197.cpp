class Solution {
public:
    long long gcdLL(long long a, long long b) {
        return b == 0 ? a : gcdLL(b, a % b);
    }

    long long lcmLL(long long a, long long b) {
        return (a / gcdLL(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long to avoid overflow
        for (int num : nums) {
            long long cur = num;
            // keep merging with previous as long as gcd > 1
            while (!st.empty() && gcdLL(st.back(), cur) > 1) {
                cur = lcmLL(st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }
        // convert back to int
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
