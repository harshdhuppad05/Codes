class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s=0,e=n-1;
        if(target-letters[e]>=0)return letters[s];
        while(s<e){
            int mid = s+(e-s)/2;
            if(target-letters[mid]>=0){
                s=mid+1;
            }
            else e = mid;
        }
        return letters[e];
    }
};
