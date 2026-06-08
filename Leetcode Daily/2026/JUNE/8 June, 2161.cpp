class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int>f;
        queue<int>c;
        queue<int>l;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)f.push(nums[i]);
            else if(nums[i] == pivot)c.push(nums[i]);
            else l.push(nums[i]);
        }
        vector<int>ans;
        while(!f.empty()){
            ans.push_back(f.front());
            f.pop();
        }
        while(!c.empty()){
            ans.push_back(c.front());
            c.pop();
        }
        while(!l.empty()){
            ans.push_back(l.front());
            l.pop();
        }
        return ans;
    }
};
