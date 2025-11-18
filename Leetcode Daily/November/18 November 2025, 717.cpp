class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(bits[n-1]!= 0)return false;
        int i = 0;
        for(i = 0;i<n-1;i++){
            if(bits[i] == 1)i++;
        }
        if(i == n-1)return true;
        return false;
    }
};
