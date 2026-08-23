class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.size();
        int sum1=0,sum2=0,count1=0,count2=0;
        for(int i=0;i<n/2;i++)
        {
            if(nums[i] == '?')count1++;
            if(nums[n/2+i] == '?')count2++;
            if(nums[i]-'0'>=0 && nums[i]-'0'<=9)sum1+=nums[i]-'0';
            if(nums[n/2+i]-'0'>=0 && nums[n/2+i]-'0'<=9)sum2+=nums[n/2+i]-'0';
        }
        return !(2*(sum1-sum2) == (count2-count1)*9);
    }
};
