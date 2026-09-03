class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isalleven = true;
        int mini = 1e9+1;
        for(auto it:nums1){
            mini = min(it, mini);
            if(it%2==1)isalleven=false;
        }
        if(mini%2==0 && !isalleven)return false;
        return true;
    }
};
