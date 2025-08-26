class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int max_d = 0;
        for(auto it:dimensions){
            int a = it[0];
            int b = it[1];
            int curr_d = (a*a) + (b*b);
            if(curr_d>max_d){
                max_d = curr_d;
                ans =  a*b;
            }else if(curr_d == max_d){
                ans = max(ans, a*b);
            }
        }
        return ans;
    }
};
