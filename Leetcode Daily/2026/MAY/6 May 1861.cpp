class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>mat(m, vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(boxGrid[i][j] == '#')count++;
                else if(boxGrid[i][j] == '*'){
                    mat[j][n-1-i] = '*';
                    int k=j-1;
                    if(count)while(count && k>=0){
                        mat[k--][n-1-i] = '#';
                        count--;
                    }
                }
            }
            int k = m-1;
            if(count){
                while(count && k>=0){
                    mat[k--][n-1-i] = '#';
                    count--;
                }
            }
        }
        return mat;
    }
};
