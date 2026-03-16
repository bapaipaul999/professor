class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for (int i = 0; i< strs[0].size() ; i++){
            int x= strs[0][i];
            bool y = true;
            for(int j = 1 ; j< n ; j++){
                if(strs[j].size()<= i || x != strs[j][i]){
                    y = false;
                    break;
                }

            }
            if(y == true){
                ans+=x;
            }
            else{
                break;
            }
        }
        return ans;
    }
};