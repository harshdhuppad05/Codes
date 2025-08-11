class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int mod = 1e9+7;
        for(int i=0;i<32;i++){
            if(n& (1<<i))powers.push_back(1<<i);
        }
        vector<int> ans;
        for(auto it:queries){
            int a=it[0],b=it[1];
            long temp = 1;
            for(int i = a;i<=b;i++){
                temp=((temp%mod)*powers[i])%mod;
            }
            ans.push_back(temp%mod);
        }
        return ans;
    }
};
