class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        if(m<n)return 0;
        sort(batteries.begin(), batteries.end());
        long long extra = 0;
        for(int i = 0;i<m-n;i++){
            extra+=batteries[i];
        }
        vector<int> live(batteries.begin()+m-n, batteries.end());
        for(int i=0;i<n-1;i++){
            if(extra<(long)(i+1)*(live[i+1]-live[i])){
                return live[i]+extra/(long)(i+1);
            }
            extra-=(long)(i+1)*(live[i+1]-live[i]);
        }
        return live[n-1]+extra/n;
    }
};
