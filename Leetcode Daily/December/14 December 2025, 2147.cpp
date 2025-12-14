class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int>sofa;
        int MOD=1e9+7;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                sofa.push_back(i);
            }
        }
        if(sofa.size()%2!=0 || sofa.size()==0)return 0;
        if(sofa.size()==2)return 1;
        long long ans = 1;
        int prev = sofa[1];
        for(int i =2;i<sofa.size();i+=2){
            int len = sofa[i]-prev;
            ans = (ans*len)%MOD;
            prev = sofa[i+1];
        }
        return ans;
    }
};
