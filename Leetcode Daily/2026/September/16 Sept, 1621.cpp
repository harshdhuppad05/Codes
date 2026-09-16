class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * modInverse(i, MOD) % MOD;
        }

        return ans;
    }

    long long modInverse(long long a, long long MOD) {
        return power(a, MOD - 2, MOD);
    }

    long long power(long long a, long long b, long long MOD) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }
};
