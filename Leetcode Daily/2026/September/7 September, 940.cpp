class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> end(26, 0);
        long long total = 0;

        for(char c : s) {
            long long newCount = (total + 1) % MOD;

            total = (total + newCount - end[c - 'a'] + MOD) % MOD;

            end[c - 'a'] = newCount;
        }

        return total;
    }
};
