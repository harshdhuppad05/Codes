class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;
        for(int i=10;i>0;i--){
            if(n-i<0){
                return (count%2==0?false:true);
            }
            n-=i;
            count++;
        }
        return true;
    }
};
