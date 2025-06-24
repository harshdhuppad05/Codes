class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == key) // if we find the key
            {
                int start = max(0, i-k);   // initialize the start
                int end = min(n-1, i+k);   // intialize the end
                
                if(ans.size()!=0) // check if any index is stored earlier
                    start = max(ans[ans.size() - 1] + 1, start); // avoid overlapping intervals
                
                for(int j = start; j<=end; j++) // simply push every index from start till end
                    ans.push_back(j);
            }
        }
        return ans;
    }
};
