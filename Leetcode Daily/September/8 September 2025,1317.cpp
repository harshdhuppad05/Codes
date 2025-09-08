class Solution {
public:
    bool containZero(int a){
        while(a){
            if(a%10 == 0)return true;
            a = a/10; 
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1;i<=n/2;i++){
            if(containZero(i) || containZero(n-i))continue;
            return {i,n-i};
        }
        return {-1,-1};
    }
};
