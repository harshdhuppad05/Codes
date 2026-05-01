class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp+=i*nums[i];
        }
        int ans=temp;
        cout<<temp<<sum;
        for(int i=nums.size()-1;i>=1;i--){
            int k = temp+sum-((nums.size())*nums[i]);
            temp=k;
            ans = max(ans,k);
        }
        return ans;
    }
};  
