
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans(num, '0');
        int i = 0;

        while (sum >= 9 && i < num) {
            ans[i++] = '9';
            sum -= 9;
        }

        if (i < num && sum > 0) {
            ans[i] = '0' + sum;
        }

        return ans;
    }
};
