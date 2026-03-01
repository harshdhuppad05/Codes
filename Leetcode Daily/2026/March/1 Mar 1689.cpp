class Solution {
public:
    int minPartitions(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            ans = max(ans, s[i]-'0');
        }
        return ans;
    }
};
