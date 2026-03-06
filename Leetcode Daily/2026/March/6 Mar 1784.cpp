class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=0;i<s.size()-1;i++){
            if(s[i] != s[i+1] && s[i] == '0')return false;
        }
        return true;
    }
};
