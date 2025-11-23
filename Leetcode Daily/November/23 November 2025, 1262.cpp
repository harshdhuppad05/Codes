class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int m1fir = 10001, m1sec = 10001, m2fir = 10001, m2sec = 10001;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] % 3 == 1)
            {
                if (nums[i] < m1fir)
                {
                    m1sec = m1fir;
                    m1fir = nums[i];
                }
                else if (nums[i] < m1sec) m1sec = nums[i];
            }
            else if (nums[i] % 3 == 2)
            {
                if (nums[i] < m2fir)
                {
                    m2sec = m2fir;
                    m2fir = nums[i];
                }
                else if (nums[i] < m2sec) m2sec = nums[i];
            }
        }
        if (sum % 3 == 0) return sum;
        if (sum % 3 == 1) return sum - min(m1fir, m2fir + m2sec);
        return sum - min(m2fir, m1fir + m1sec);
    }
};
