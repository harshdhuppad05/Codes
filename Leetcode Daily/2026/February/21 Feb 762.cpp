class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            int bits = 0;
            int n = i;
            while(n){
                bits += n & 1;
                n=n>>1;
            }
            cnt += primes.count(bits);
        }
        return cnt;
    }
};
