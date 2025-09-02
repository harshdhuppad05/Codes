class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0]; 
    }
    return a[1] > b[1];
});
        int n = points.size();
        int ans=0;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int b = points[i][1];
                int d = points[j][1];
                int flag = 1;
                if(d>b)continue;
                for(int k=i+1;k<j;k++){
                    int f = points[k][1];
                    if(f<=b && f>=d){
                        flag=0;
                        break;
                    }
                }
                if(flag)ans++;
            }
        }
        return ans;
    }
};
