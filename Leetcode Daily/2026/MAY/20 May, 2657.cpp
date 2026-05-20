class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>arr(n+1,0);
        vector<int> ans;
        vector<int>vis(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            arr[A[i]]++;
            arr[B[i]]++;
            if(arr[A[i]]>=2 && !vis[A[i]]){
                count++;
                vis[A[i]]=1;
            }
            if(arr[B[i]]>=2 && !vis[B[i]]){
                count++;
                vis[B[i]]=1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
