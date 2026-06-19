class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currsum = 0, ans=0;
        for(auto it:gain){
            currsum+=it;
            ans= max(ans,currsum);
        }
        return ans;
    }
};
