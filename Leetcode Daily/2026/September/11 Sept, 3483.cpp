class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;

        for (int d : digits) {
            mp[d]++;
        }

        int ans = 0;

        // Last digit must be even
        for (int last = 0; last <= 8; last += 2) {

            if (mp[last] == 0)
                continue;

            // Use the last digit
            mp[last]--;

            // Choose first digit (1-9)
            for (int first = 1; first <= 9; first++) {

                if (mp[first] == 0)
                    continue;

                // Use first digit
                mp[first]--;

                // Choose second digit (0-9)
                for (int second = 0; second <= 9; second++) {
                    if (mp[second] > 0)
                        ans++;
                }

                // Restore first digit
                mp[first]++;
            }

            // Restore last digit
            mp[last]++;
        }

        return ans;
    }
};
