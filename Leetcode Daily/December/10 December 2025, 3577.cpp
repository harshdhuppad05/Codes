class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long count = 1;
        int a = complexity[0];
        int MOD = 1e9+7;
        for(int i = 1;i<complexity.size();i++){
            if(a>=complexity[i])return 0;
            count=(count*i)%MOD;
        }
        return count;
    }
};
