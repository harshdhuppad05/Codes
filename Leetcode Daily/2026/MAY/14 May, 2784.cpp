class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int>arr(n+1,0);
        if(nums.size()!=n+1)return false;
        for(auto i:nums){
            arr[i]++;
        }
        for(int i=1;i<n-1;i++){
            if(arr[i]!=1)return false;
        }
        if(arr[n]!=2)return false;
        return true;
    }
};
