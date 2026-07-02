class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1};

    bool dfs(int i, int j,
             vector<vector<int>>& grid,
             int health,
             vector<vector<int>>& best) {

        int n = grid.size();
        int m = grid[0].size();

        if (health < 1)
            return false;

        if (i == n - 1 && j == m - 1)
            return true;

        // We've already been here with equal or more health.
        if (best[i][j] >= health)
            return false;

        best[i][j] = health;

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            int newHealth = health - grid[ni][nj];

            if (dfs(ni, nj, grid, newHealth, best))
                return true;
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        health -= grid[0][0];

        if (health < 1)
            return false;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m, -1));

        return dfs(0, 0, grid, health, best);
    }
};
