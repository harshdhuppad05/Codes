class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101,0);
        for(int it:nums){
            arr[it]++;
        }
        int ans=0;
        int maxf = 0;
        for(int i=0;i<101;i++){
            if(maxf<arr[i]){
                ans=arr[i];
                maxf = arr[i];
            }
            else if(maxf == arr[i]){
                ans+=maxf;
            }
        }
        return ans;
    }
};
