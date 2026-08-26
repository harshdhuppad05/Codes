class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        map<int, vector<string>>mp;
        int i=0,j=0,n=s.size();
        int count =0;
        while(i<=j && j<=n){
            if(count == k){
                while(count==k){
                    mp[j-i+1].push_back(s.substr(i,j-i));
                    if(s[i]=='1')count--;
                    i++;
                }
            }
            if(s[j]=='1')count++;
            j++;
        }
        if(mp.size()==0)return "";
        // cout<<mp.size()<<endl;
        auto it = mp.begin();
        vector<string> arr = it->second;
        sort(arr.begin(), arr.end());
        return arr[0];
    }
};
