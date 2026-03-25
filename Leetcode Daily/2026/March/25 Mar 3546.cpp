class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long totalsum = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<long>horizontal(n,0);
        for(int i = 0;i<n;i++){
            long temp = 0;
            for(int j = 0;j<m;j++){
                totalsum+=grid[i][j];
                temp+=grid[i][j];
            }
            horizontal[i] = temp;
        }
        if(totalsum%2!=0)return false;
        long curr=0;
        for(int i=0;i<n;i++){
            curr+=horizontal[i];
            if(curr==totalsum/2)return true;
        }
        curr=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                curr+=grid[i][j];
            }
            if(curr == totalsum/2)return true;
        }
        return false;
    }
};
