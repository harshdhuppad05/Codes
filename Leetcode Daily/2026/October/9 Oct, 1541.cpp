class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int open=0;
        int close=0;
        int i=0;
        int n = s.size();
        while(i<n){
            if(s[i]=='(')open++;
            if(s[i] == ')'){
                i++;
                if(i<n && s[i]!=')'){
                    ans++;
                    i--;
                }
                else if(i==n){
                    ans++;
                }
                open--;
                if(open<0){
                    ans++;
                    open=0;
                }
            }
            i++;
        }
        return ans+2*open;
    }
};
