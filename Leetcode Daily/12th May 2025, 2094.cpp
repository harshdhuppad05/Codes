brute force
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        set<int> st;
        int n = digits.size();
        sort(digits.begin(), digits.end());
        for(int i = 0;i<n; i++){
            for(int j = 0;j<n; j++){
                for(int k = 0;k<n;k++){
                    if(digits[i]!=0 && digits[k]%2==0 && i!=j && i!=k && k!=j){
                        int d = digits[i]*100+digits[j]*10+digits[k];
                        st.insert(d);
                    }
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

optimal solution -:

class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    // generating frequency map of the given digits
    vector<int> count(10, 0);
    for (auto& d : digits) count[d]++;

    vector<int> res;

    for (int num = 100; num < 999; num += 2) {
      // generating frequency map of the current number
      vector<int> currCount(10, 0);
      int temp = num;

      while (temp) {
        currCount[temp % 10]++;
        temp /= 10;
      }

      // checking if the number can be generated or not
      bool flag = true;
      for (int i = 0; i < 10; i++) {
        if (currCount[i] > count[i]) {
          flag = false;
          break;
        }
      }

      if (flag) {
        res.push_back(num);
      }
    }
    return res;
  }
};
