class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        numBottles = 0;
        while(numBottles!=0 || numBottles+empty>=numExchange){
            if(empty>=numExchange){
                empty-=numExchange;
                numBottles++;
                numExchange++;
            }else{
                ans+=numBottles;
                empty+=numBottles;
                numBottles = 0;
            }
        }
        return ans;
    }
};
