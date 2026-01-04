class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans= 0;
       
        for(int j=0;j<nums.size();j++){
            unordered_set<int>temp;
            for(int i = 2;i*i<=nums[j];i++){
                if(nums[j]%i == 0){
                    temp.insert(i);
                    temp.insert(nums[j]/i);
                }
                if(temp.size()>2)break;
            }
            if(temp.size() == 2){
                ans+=1+nums[j];
                for(auto it:temp){
                    ans+=it;
                }
            }
        }
        return ans;
    }
};
