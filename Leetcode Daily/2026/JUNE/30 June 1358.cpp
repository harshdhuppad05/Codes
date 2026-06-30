class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int j=0;
        int n = s.size();
        int a=0,b=0,c=0;
        int ans=0;
        while(i<=j && j<=n){
            if(a && b && c){
                while(i<j && a>0 && b>0 &&c>0){
                    ans+= n-j+1;
                    if(s[i] == 'a')a--;
                    if(s[i] == 'b')b--;
                    if(s[i] == 'c')c--;
                    i++;
                }
            }
            if(s[j] == 'a')a++;
            if(s[j] == 'b')b++;
            if(s[j] == 'c')c++;
            j++;
        }
        return ans;
    }
};
