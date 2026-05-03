class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size())return false;
        for(int i=0;i<s.size();i++){
            if(s[i] == goal[0]){
                int j=0,k=i;
                while(j<goal.size()){
                    if(s[k++]!=goal[j])break;
                    k%=s.size();
                    j++;
                }
                if(j==goal.size())return true;
            }
        }
        return false;
    }
};
