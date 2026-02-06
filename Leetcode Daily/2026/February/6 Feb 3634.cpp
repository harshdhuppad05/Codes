class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        
        int swap=0;
        for(int r=0;r<n;r++){
            while(nums[r]>(long long)nums[l]*k){
                l++;
            }
            swap=max(swap,r-l+1);
        }
        
        return n-swap;
    }
};
