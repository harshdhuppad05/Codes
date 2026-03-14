class Solution {
public:
    vector<string> ans;
    vector<char>arr = {'a','b','c'};
    void allStrings(int i, int n, string &s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        for(auto c:arr){
            if(s.empty() || s.back()!=c){
                s.push_back(c);
                allStrings(i+1, n, s);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string tmp = "";
        allStrings(0,n, tmp);
        if(k>ans.size())return "";
        return ans[k-1];
    }
};
