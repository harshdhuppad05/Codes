class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count = 0;
        unordered_map<char, int> mp;
        for(auto it:text){
            mp[it]++;
        }
        string bal = "balloon";
        int i=0;
        int n = bal.size();
        while(true){
            if(mp.find(bal[i])==mp.end())break;
            else mp[bal[i]]--;
            if(mp[bal[i]] <= 0)mp.erase(bal[i]);
            if(i==n-1){
                i=-1;
                count++;
            }
            i++;
        }
        return count;
    }
};
