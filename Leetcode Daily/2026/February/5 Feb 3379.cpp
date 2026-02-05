class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        for(int i = 0;i<n;i++){
            if(nums[i]>0)res[i] = nums[(i+nums[i])%n];
            else if(nums[i] == 0)res[i] = nums[i];
            else{
                cout<<(n+(i-abs(nums[i])))%n<<endl;
                res[i] = nums[(n+(i-abs(nums[i])%n))%n];
            }
        }

        return res;
    }
};
