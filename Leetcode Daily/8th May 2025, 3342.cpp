class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0,});
        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int t = temp[0];
            int i = temp[1];
            int j = temp[2];
            if(t>=time[i][j])continue;
            if(i==n-1 && j == m-1)return t;
            time[i][j] = t;
            for(auto d:dir){
                int ni = d[0]+i;
                int nj = d[1]+j;
                int c = (i+j)%2+1;
                if(ni>=0 && nj>=0 && ni<n && nj<m && time[ni][nj] == INT_MAX){
                    pq.push({max(moveTime[ni][nj],t)+c, ni, nj});
                }
            }
        }
        return -1;
    }
};
