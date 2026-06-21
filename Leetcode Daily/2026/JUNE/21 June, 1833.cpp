class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(), costs.end());
        vector<int> count(m+1);
        int n = costs.size();
        for(int i=0;i<n;i++){
            count[costs[i]]++;
        }
        for(int i=1;i<m+1;i++){
            count[i]+=count[i-1];
        }
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            ans[count[costs[i]]-1]=costs[i];
            count[costs[i]]--;
        }
        int final=0;
        for(int i=0;i<n;i++){
            if(coins>=ans[i]){
                final++;
                coins-=ans[i];
            }
            else break;
        }
        return final;
    }
};
