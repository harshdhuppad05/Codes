class Solution {
public:
    int minOperations(string s) {
        int count1=0;
        int count2=0;
        char curr = '0';
        char curr2= '1';
        for(int i =0;i<s.size();i++){
            if(curr!= s[i]){
                count1++;
            }
            if(curr2!= s[i]){
                count2++;
            }
            curr= curr=='0'?'1':'0';
            curr2= curr2=='0'?'1':'0';
        }
        return min(count1, count2);
    }
};
