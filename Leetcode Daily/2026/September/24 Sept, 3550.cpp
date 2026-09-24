class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int t = 0,c=nums[i];
            while(c){
                t+=c%10;
                c=c/10;
            }
            if(t==i)return i;
        }
        return -1;
    }
};
