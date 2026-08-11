class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int>hash(52,0);
        int sum=nums[0];
        bool flag=true;
        hash[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            if(flag  && nums[i]==nums[i-1]+1)sum+=nums[i];
            else flag=false;
            hash[nums[i]]++;
        }
        if(sum>50)return sum;
        while(hash[sum]){
            sum++;
        }
        return sum;
    }
};
