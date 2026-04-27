class Solution {
public:
    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{0,1},{1,0}},
        {{0,-1},{-1,0}},
        {{0,1},{-1,0}}
    };

    bool isValid(int ni, int nj, int i, int j, vector<vector<int>>& grid) {
        int type = grid[ni][nj];
        
        for(auto d : dirs[type]) {
            int x = ni + d[0];
            int y = nj + d[1];
            if(x == i && y == j) return true;
        }
        return false;
    }

    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size(), m = grid[0].size();

        if(i == n-1 && j == m-1) return true;

        vis[i][j] = true;

        for(auto d : dirs[grid[i][j]]) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj]) {
                if(isValid(ni, nj, i, j, grid)) {
                    if(dfs(ni, nj, grid, vis)) return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        return dfs(0, 0, grid, vis);
    }
};
