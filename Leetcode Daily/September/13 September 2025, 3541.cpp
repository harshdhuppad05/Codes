class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        int mx1= 0;
        int mx2=0;
        for(int i=0;i<26;i++){
            if(i==0||i==4||i==8||i==14||i==20){
                mx1 = max(mx1,arr[i]);
            }
            else mx2=max(mx2,arr[i]);
        }
        return mx1+mx2;
    }
};
