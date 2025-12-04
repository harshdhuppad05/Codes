class Solution {
public:
    int countCollisions(string directions) {
        int ans= 0;
        int accident = 0;
        int curr = 0;
        for(auto c:directions){
            if(c == 'L'){
                if(accident > 0 || curr>0){
                    curr++;
                    ans+=curr;
                    curr = 0;
                    accident = 1;
                }
            }
            else if(c == 'S'){
                accident = 1;
                ans+=curr;
                curr = 0;
            }
            else{
                curr++;
            }
        }
        return ans;
    }
};
