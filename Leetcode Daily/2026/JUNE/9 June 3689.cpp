class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> arr = nums; 
        
        int mx = *max_element(arr.begin(), arr.end());
        int mn = *min_element(arr.begin(), arr.end());
        
        long long best = (long long)mx - mn;
        return best * k;
    }
};
