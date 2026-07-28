class Solution {
public:
    string smallestPalindrome(string s) {
        string t1="",t2="";
        vector<int>arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        int odd=-1;
        for(int i=0;i<26;i++){
            int t=arr[i];
            char c='a'+i;
            while(t>=2){
                t1+=c;
                t2+=c;
                t-=2;
            }
            if(t==1)odd=i;
        }
        if(odd!=-1){
            char c = 'a'+odd;
            t1+=c;
        }
        
        reverse(t2.begin(),t2.end());
        t1+=t2;
        return t1;
    }
};
