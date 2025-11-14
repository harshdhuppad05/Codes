class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int> (n,0));
        for(auto q:queries){
            int si = q[0],sj=q[1];
            int ei=q[2], ej=q[3];
            for(int i = si;i<=ei;i++){
                for(int j=sj;j<=ej;j++){
                    mat[i][j] += 1;
                }
            }
        }
        return mat;
    }
};
