class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,c=0;
        for(auto it:moves){
            if(it=='L')l++;
            else if(it == 'R')r++;
            else c++;
        }
        return c+abs(r-l);
    }
};
