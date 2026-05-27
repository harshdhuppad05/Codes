class Solution {
public:
    int numberOfSpecialChars(string w) {
        vector<int>small(26,0);
        vector<int>large(26,0);
        vector<int>isWrong(26,0);
        int n = w.size();
        for(int i=n-1;i>=0;i--){
            if(w[i]>='A'&& w[i]<='Z'){
                large[w[i]-'A']++;
                if(small[tolower(w[i])-'a']>0)isWrong[w[i]-'A']=1;
            }
            else{
                small[w[i]-'a']++;
            }
        }
        int ans=0;
        for(int i = 0;i<26;i++){
            if(small[i]>0 && large[i]>0 && isWrong[i]==0)ans++;
        }
        return ans;
    }
};
