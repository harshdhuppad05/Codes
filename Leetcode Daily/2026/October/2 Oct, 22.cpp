class Solution {
public:
    vector<string> ans;
    void generate(int i, int n, string temp, int count){
        if (i==2*n-1){
            temp.push_back(')');
            count--;
            if(count==0)ans.push_back(temp);
            return;
        }
        if(count==0){
            generate(i+1,n,temp+'(',count+1);
        }
        else{
            generate(i+1,n,temp+'(',count+1);
            generate(i+1,n,temp+')',count-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(1,n,"(",1);
        return ans;
    }
};
