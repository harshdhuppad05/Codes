class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false), visited(n, false);
        queue<int> q;
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) q.push(box);
        }
        
        int ans = 0;
        while (!q.empty()) {
            int box = q.front(); q.pop();
            if (visited[box]) continue;
            visited[box] = true;
            ans += candies[box];
            
            for (int k : keys[box]) {
                if (status[k] == 0) {
                    status[k] = 1;
                    if (hasBox[k]) q.push(k); 
                }
            }
            
            for (int b : containedBoxes[box]) {
                hasBox[b] = true;
                if (status[b] == 1) q.push(b);
            }
        }
        
        return ans;
    }
};
