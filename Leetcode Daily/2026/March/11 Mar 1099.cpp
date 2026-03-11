class Solution {
public:
    int bitwiseComplement(int n) {
        int ans=0;
        int count=1;
        if(n==0)return 1;
        while(n>0){
            if(n%2==1)ans+=0*count;
            else ans+=1*count;
            count*=2;
            n/=2;
        }
        return ans;
    }
};
