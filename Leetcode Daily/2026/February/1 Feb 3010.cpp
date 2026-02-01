class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int m1=51;
        int m2=52;
        for(int i = 1;i<nums.size();i++){
            int it=nums[i];
            if(m1<m2){
                m2 = min(it,m2);
            }
            else{
                m1 = min(it,m1);
            }
        }
        return m1+m2+nums[0];
    }
};
