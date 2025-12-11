class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>top(n+1,100001),bottom(n+1,0),right(n+1,0),left(n+1,100001);
        int ans = 0;
        for(auto it:buildings){
            int x = it[0];
            int y = it[1];
            top[y] = min(top[y],x);
            left[x] = min(left[x],y);
            bottom[y] = max(bottom[y],x);
            right[x] = max(right[x],y);
        }
        for(auto it:buildings){
            int x = it[0];
            int y = it[1];
            if (top[y] < x && bottom[y] > x && left[x] < y && right[x] > y)ans++;
        }
        return ans;
    }
};
