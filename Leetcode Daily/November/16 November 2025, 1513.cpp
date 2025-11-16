class Solution {
public:
    int numSub(string s) {
        long ans=0;
        int i=0;
        long mod = 1e9+7;
        long count = 0;
        while(i<s.size()){
            while(i<s.size() && s[i] == '1'){
                count++;
                i++;
            }
            ans+=((count*(count+1))/2)%mod;
            if(count)i--;
            count=0;
            i++;
        }
        return ans;
    }
};
