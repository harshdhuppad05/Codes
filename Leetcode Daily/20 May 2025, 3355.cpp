class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n+1,0);
        for(auto it:queries){
            arr[it[0]]++;
            arr[it[1]+1]--;
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            count+=arr[i];
            if(count<nums[i])return false;
        }
        return true;
    }
};
