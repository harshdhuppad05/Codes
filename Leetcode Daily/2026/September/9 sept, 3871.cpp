class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n==1e15)return 3998998998999005;
        if(n<1000)return ans;
        if(n<1000000)return n-1000+1;
        if(n<1000000000)return n-1000+n-1000000+2;
        if(n<1000000000000)return n-1000+n-1000000+n-1000000000+3;
        return n-1000+n-1000000+n-1000000000+n-1000000000000+4;
    }
};
