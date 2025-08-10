class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<string, int> mp;
        int t = 1;
        while(t<pow(10,9)){
            string s = to_string(t);
            sort(s.begin(), s.end());
            mp[s]++;
            t*=2;
        }
        string str = to_string(n);
        sort(str.begin(),str.end());
        if(mp.find(str)!= mp.end())return true;
        return false;
    }
};
