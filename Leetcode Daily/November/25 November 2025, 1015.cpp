class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 ==0 || k%5 == 0)return -1;
        int count = 1;
        int rem = 1;
        while(true){
            if(rem%k == 0)return count;
            rem = ((rem*10)%k + 1)%k;
            count++;
        }
    }
};
