class Solution {
public:
    bool solve(int start, vector<int>&arr, vector<int>&vis){
        if(start>=arr.size()|| start<0 || vis[start] == 1 )return false;
        if(arr[start] == 0)return true;
        vis[start] = 1;
        return solve(start+arr[start],arr,vis) || solve(start-arr[start],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return solve(start, arr, vis);
    }
};
