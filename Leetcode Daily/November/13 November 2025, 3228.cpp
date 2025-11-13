class Solution {
public:
    int maxOperations(string s) {
        int ones= 0;
        int ans = 0;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                ones++;
            }else{
                while(i<n && s[i] =='0')i++;
                ans+=ones;
                ones++;
            }
        }
        return ans;
    }
};
