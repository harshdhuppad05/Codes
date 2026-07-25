class Solution {
public:
    int maxProduct(int n) {
        int a=0;
        int b=0;
        while(n){
            int t=n%10;
            if(a<t){
                b=a;
                a=t;
            }
            else if(b<t){
                b=t;
            }
            n=n/10;
        }
        return a*b;
    }
};
