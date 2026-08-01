class Solution {
public:
    bool predictAns(vector<int>& nums, int i, int j, int ans1, int ans2, int turn){
        if(i>j){
            return ans1>=ans2;
        }
        if(turn==1){
            bool l=predictAns(nums,i+1,j,ans1+nums[i],ans2,2);
            bool r=predictAns(nums,i,j-1,ans1+nums[j],ans2,2);
            return l||r;
        }else{
            bool l=predictAns(nums,i+1,j,ans1,nums[i]+ans2,1);
            bool r=predictAns(nums,i,j-1,ans1,nums[j]+ans2,1);
            return l&&r;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=n-1;
        int ans1=0, ans2=0;
        return predictAns(nums,i,j,ans1,ans2,1);
    }
};
