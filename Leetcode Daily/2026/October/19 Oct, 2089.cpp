class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        int count =0;
        int smaller = 0;
        for(auto it:nums){
            if(it<target)smaller++;
            if(it==target)count++;
        }
        for(int i=0;i<count;i++){
            ans.push_back(smaller+i);
        }
        return ans;
    }
};
