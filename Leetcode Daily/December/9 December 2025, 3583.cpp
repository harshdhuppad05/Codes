class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // map<int, vector<int>>mp;
        // for(int i = 0;nums.size();i++){
        //     mp[nums[i]].push_back(i);
        // }
        // int ans = 0;
        // int MOD = 1e9+7;
        // for(auto it:mp){
        //     int a=it.first;
        //     vector<int>b = it.second;
        //     if(mp.find(2*a)!=mp.end()){
        //         vector<int>c = mp[2*a];
        //         for(int i = 0;i<b.size();i++){
        //             int j = 0;
        //             int k = c.size()-1;
        //             while(j<k){
        //                 if(b[i]<c[k] && b[i]>c[j]){
        //                     j++;
        //                     ans++;
        //                 }
        //                 else break;

        //             }
        //         }
        //     }
        // }
        // vector<int>right(100001, 0);
        // vector<int> left(100001, 0);
        // for(int i = 2;i<nums.size();i++){
        //     right[nums[i]]++;
        // }
        // int count = 0;
        // int MOD = 1e9+7;
        // left[nums[0]]++;
        // for(int i = 1;i<nums.size();i++){
        //     if(left[2*nums[i]]>0 && right[2*nums[i]]>0)count=(count+left[2*nums[i]]*right[2*nums[i]])%MOD;
        //     left[nums[i]]++;
        //     right[nums[i]]--;
        // }
        // return count;
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<long long, long long> left, right;
        for (int i = 2; i < n; i++) {
            right[nums[i]]++;
        }
        long long ans = 0;
        left[nums[0]]++;
        for (int j = 1; j < n - 1; j++) {
            long long need = 2LL * nums[j];
            long long L = left[need];
            long long R = right[need];
            ans = (ans + (L * R) % MOD) % MOD;
            left[nums[j]]++;
            right[nums[j+1]]--;  
        }

        return ans;
    }
};
