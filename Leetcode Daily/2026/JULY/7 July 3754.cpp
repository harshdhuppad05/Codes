class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int sum=0;
        int i=0;
        while(n){
            int t = n%10;
            n=n/10;
            if(t!=0){
                ans=ans+t*pow(10,i);
                i++;
                sum+=t;
            }
        }
        return ans*sum;
    }
};
