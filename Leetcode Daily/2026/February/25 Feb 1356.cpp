class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> brr;
        for(auto it:arr){
            int count = __builtin_popcount(it);
            brr.push_back({count, it});
        }
        sort(brr.begin(), brr.end());
        vector<int>ans;
        for(auto it:brr){
            ans.push_back(it.second);
        }
        return ans;
    }
};
