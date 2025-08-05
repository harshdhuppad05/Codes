class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for(int i=0;i<fruits.size();i++){
            int status = 0;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    cout<<j<<endl;
                    status = 1;
                    baskets[j] = 0;
                    break;
                }
            }
            if (status == 0){
                ans++;
            }
        }
        return ans;
    }
};
