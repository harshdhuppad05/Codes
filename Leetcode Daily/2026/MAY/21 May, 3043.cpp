class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int i = 0;i<arr1.size();i++){
            int temp = arr1[i];
            while(temp){
                st.insert(temp);
                temp=temp/10;
            }
        }
        int ans = 0;
        for(int i = 0;i<arr2.size();i++){
            int temp = arr2[i];
            while(temp){
                if(st.find(temp)!=st.end()){
                    string j = to_string(temp);
                    int n = j.size();
                    ans = max(ans,n);
                    break;
                }
                temp = temp/10;
            }
        }
        return ans;
    }
};
