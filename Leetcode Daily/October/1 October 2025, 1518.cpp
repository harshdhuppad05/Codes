class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange, int empty=0) {
        if((numBottles+empty)/numExchange == 0 && numBottles ==0)return 0;
        return numBottles+numWaterBottles((numBottles+empty)/numExchange, numExchange, (numBottles+empty)%numExchange);
    }
};
