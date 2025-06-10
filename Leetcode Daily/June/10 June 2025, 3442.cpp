class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int>freq;
        for(auto ch:s){
            freq[ch]++;
        }
        int odd = 0;
        int even = 100;
        for(auto it:freq){
            if(it.second%2 ==1)odd = max(odd, it.second);
            else even = min(even, it.second);
        }
        if(even == 100)even = 0;
        return odd-even;
    }
};
