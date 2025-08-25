class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int n = mat.size();
        int m = mat[0].size();
        ans.push_back(mat[0][0]);
        while(i<=n+m && j<=m+n){
            i++;
            j=0;
            int k = i;
            vector<int> temp;
            while(k>=0 && k+j<=m+n){
                if(k<n && j<m)temp.push_back(mat[k][j]);
                k--;
                j++;
            }
            if(i%2 ==1)reverse(temp.begin(), temp.end());
            for(auto it:temp){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
