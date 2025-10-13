class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string s = words[i];
            string t = words[i-1];
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if(s == t)continue;
            else ans.push_back(words[i]);
        }
        return ans;
    }
};
