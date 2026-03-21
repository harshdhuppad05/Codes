class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int counter=0;
        for(int i=0;i<k/2;i++){
            for(int j=y;j<y+k;j++){
                swap(grid[i+x][j], grid[k-i+x-1][j]);
            }
            counter++;
        }
        return grid;
    }
};
