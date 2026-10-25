class Solution {
public:
    bool bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
             int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        bool isClosed = true;

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            isClosed = false;
        }

        if (i + 1 < n && grid[i + 1][j] == 0 && vis[i + 1][j] == -1)
            isClosed &= bfs(grid, vis, i + 1, j);

        if (j + 1 < m && grid[i][j + 1] == 0 && vis[i][j + 1] == -1)
            isClosed &= bfs(grid, vis, i, j + 1);

        if (i - 1 >= 0 && grid[i - 1][j] == 0 && vis[i - 1][j] == -1)
            isClosed &= bfs(grid, vis, i - 1, j);

        if (j - 1 >= 0 && grid[i][j - 1] == 0 && vis[i][j - 1] == -1)
            isClosed &= bfs(grid, vis, i, j - 1);

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(n, vector<int>(m, -1));

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && vis[i][j] == -1) {
                    if (bfs(grid, vis, i, j))
                        count++;
                }
            }
        }

        return count;
    }
};
