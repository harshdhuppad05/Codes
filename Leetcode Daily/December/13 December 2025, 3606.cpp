class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>e,g,p,r,ans;
        int n = code.size();
        for(int i =0;i<n;i++){
            if(isActive[i]){
                bool iscorrect = true;
                if(code[i].size()==0)iscorrect = false;
                for (char c : code[i]) {
                    if (!isalnum(c) && c != '_') {
                        iscorrect = false;
                        break;
                    }
                }
                if(iscorrect){
                    if(businessLine[i] == "electronics")e.push_back(code[i]);
                    if(businessLine[i] == "grocery")g.push_back(code[i]);
                    if(businessLine[i] == "pharmacy")p.push_back(code[i]);
                    if(businessLine[i] == "restaurant")r.push_back(code[i]);
                }
            }
        }
        sort(e.begin(),e.end());
        sort(g.begin(),g.end());
        sort(p.begin(),p.end());
        sort(r.begin(),r.end());
        for(auto it:e){
            ans.push_back(it);
        }
        for(auto it:g){
            ans.push_back(it);
        }
        for(auto it:p){
            ans.push_back(it);
        }
        for(auto it:r){
            ans.push_back(it);
        }
        return ans;
    }
};
