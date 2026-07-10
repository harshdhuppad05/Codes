class Solution {
public:
    vector<int> pathExistenceQueries(int n,vector<int>& nums,int maxDiff,vector<vector<int>>& queries){
        // (value, original index)
        vector<pair<int, int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // original index -> position in sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // right[i] = farthest position reachable in one jump
        vector<int> right(n);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n &&
                   arr[j + 1].first - arr[i].first <= maxDiff)
                j++;
            right[i] = j;
        }

        int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = right[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = pos[q[0]];
            int r = pos[q[1]];

            if (l > r)
                swap(l, r);

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            int cur = l;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < r) {
                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            if (right[cur] >= r)
                ans.push_back(jumps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
