class Solution {
public:
    string sortVowels(string s) {
        string t = s;
        vector<int> pos;
        string temp = "";
        for(int i = 0;i<s.size();i++){
            char it = s[i];
            if(it == 'a'|| it == 'e'|| it == 'o'||it=='i' || it =='u'|| it == 'A'|| it == 'E'|| it == 'O'||it=='I' || it =='U'){
                pos.push_back(i);
                temp+=it;
            }
        }
        sort(temp.begin(),temp.end());
        for(int i = 0;i<temp.size();i++){
            t[pos[i]] = temp[i];
        }
        return t;
    }
};
