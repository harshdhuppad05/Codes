class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int k=n;
            int product=1;
            while(k>=1){
                product*=k%10;
                k/=10;
            }
            if(product%t==0)return n;
            n++;
        }
        return n;
    }
};
