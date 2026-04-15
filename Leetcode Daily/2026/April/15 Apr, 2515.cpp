class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string, vector<int>> mp;
        int i=0;
        for(auto it:words){
            mp[it].push_back(i);
            i++;
        }
        int ans = 101;
        int n = words.size();
        if(mp.find(target)!=mp.end()){
            auto it = mp[target];
            for(int j=0;j<it.size();j++){
                ans = min(abs(it[j]-startIndex), ans);
                ans= min(ans, n-abs(it[j]-startIndex));
            }
        }
        else return -1;
        return ans;
    }
};
