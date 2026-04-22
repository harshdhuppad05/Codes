class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto q:queries){
            for(auto it:dictionary){
                int count=0;
                for(int i=0;i<q.size();i++){
                    if(q[i]!=it[i])count++;
                    if(count>2)break;
                }
                if(count<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }

};
