class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0,sum2=0;
        long long count1 = 0, count2 = 0;
        for(auto it: nums1){
            if(it == 0)count1++;
            sum1+=it;
        }
        for(auto it:nums2){
            if(it == 0)count2++;
            sum2+=it;
        }
        if(count1==0 && sum1<sum2+count2) return -1;
        if(count2==0 && sum2<sum1+count1) return -1;
        
        return max(sum1+count1,sum2+count2);
    }
};
