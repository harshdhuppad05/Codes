class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr;

        // Count trailing zeros in each row
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 0) count++;
                else break;
            }
            arr.push_back(count);
        }

        int ans = 0;

        // Greedy placement
        for(int i = 0; i < n; i++){
            int required = n - 1 - i;
            int j = i;

            // Find first row satisfying requirement
            while(j < n && arr[j] < required) {
                j++;
            }

            if(j == n) return -1;

            // Bring row to position i using adjacent swaps
            while(j > i){
                swap(arr[j], arr[j - 1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};2 Mar 
