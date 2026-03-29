class Solution {
public:
    bool canBeEqual(string s1, string s2) {
    //sort(s1.begin(), s1.end());
    //sort(s2.begin(), s2.end());
    if (s1 == s2) {
        return true;
    }
    unordered_map<char, int> c1, c2;
    
    for (char c : s1) {
        c1[c]++;
    }
    
    for (char c : s2) {
        c2[c]++;
    }
    
    if (c1 != c2) {
        return false;
    }
    for (int i = 0; i < s1.length() - 2; i++) {
        if (s1[i] != s2[i] && s1[i+2] != s2[i+2] && s1[i] == s2[i+2] && s1[i+2] == s2[i]) {
            return true;
        }
    }
    
    return false;
    }
};
