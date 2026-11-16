class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        if(n<=k)return s;
        string ans = "";
        for(int i=0;i<n;i+=k){
            int count = 0;
            for(int j=i;j<min(i+k,n);j++){
                count+=s[j]-'0';
            }
            ans+=to_string(count);
        }
        return digitSum(ans, k);
    }
};
