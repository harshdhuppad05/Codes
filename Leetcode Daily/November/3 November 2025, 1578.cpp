class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char c = colors[0];
        int ans = 0;
        for(int i=1;i<colors.size();i++){
            int max_time = neededTime[i-1];
            bool flag = false;
            if(c == colors[i])ans+=neededTime[i-1];
            while(c == colors[i]){
                ans+=neededTime[i];
                max_time = max(max_time, neededTime[i]);
                flag = true;
                i++;
            }
            if(flag){
                ans-=max_time;
            }
            c = colors[i];
        }
        return ans;
    }
};
