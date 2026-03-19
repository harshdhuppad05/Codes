int numberOfSubmatrices(vector<vector<char>>& grid) {
    int ans = 0;
    vector<vector<pair<int,int>>> v(grid.size(), vector<pair<int,int>>(grid[0].size(), {0, 0}));
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){ 
            if(j > 0 ) {
                v[i][j].first = v[i][j-1].first;
                v[i][j].second = v[i][j-1].second;
            }
            if(i > 0) {
                v[i][j].first += v[i-1][j].first;
                v[i][j].second += v[i-1][j].second;
            }
            if(i > 0 && j > 0) {
                v[i][j].first -= v[i-1][j-1].first;
                v[i][j].second -= v[i-1][j-1].second;
            }
            if(grid[i][j] == 'X') v[i][j].first++;
            else if(grid[i][j] == 'Y') v[i][j].second++;
            if(v[i][j].first && v[i][j].first == v[i][j].second) ans++;
        }
    }
    return ans;
}
