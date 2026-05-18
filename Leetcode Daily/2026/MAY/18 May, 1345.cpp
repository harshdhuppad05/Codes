class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(n, 0);
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0] = 1;
        while (!q.empty()) {
            auto [index, steps] = q.front();
            q.pop();
            if (index == n - 1)
                return steps;
            if (index + 1 < n && !vis[index + 1]) {
                vis[index + 1] = 1;
                q.push({index + 1, steps + 1});
            }
            if (index - 1 >= 0 && !vis[index - 1]) {
                vis[index - 1] = 1;
                q.push({index - 1, steps + 1});
            }
            for (auto nextIndex : mp[arr[index]]) {
                if (!vis[nextIndex]) {
                    vis[nextIndex] = 1;
                    q.push({nextIndex, steps + 1});
                }
            }
            mp[arr[index]].clear();
        }

        return -1;
    }
};
