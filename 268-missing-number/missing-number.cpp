class Solution {
public:
    int missingNumber(vector<int>& nums) {
      set<int>check;
      int maxi = 0;
      for(auto i: nums){
        maxi = max(maxi , i);
        check.insert(i);
      } 

      for(int i = 0; i<maxi ; i++){
        if(check.find(i)==check.end()){
            return i;
        }
      }
      return maxi+1;

    }
};