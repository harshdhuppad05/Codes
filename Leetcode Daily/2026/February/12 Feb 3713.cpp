class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            unordered_map<char, int>mp;
            for(int j = i;j<s.size();j++){
                mp[s[j]]++;
                int val = mp[s[j]];
                int flag = 0;
                for(auto it:mp){
                    if(it.second!=val){
                        flag =1;
                        break;
                    }
                }
                if(!flag)ans= max(ans, j-i+1);
            }
            mp.clear();
        }
        return ans;
    }
};
