class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>temp;
        int idx = 0;
        for(auto it : boxes){
            if(it == '1'){
                temp.push_back(idx);
            }
            idx++;
        }
        idx = 0;
        vector<int>ans;
        for(auto it : boxes){
            int sum = 0;
            for(int i = 0 ; i<temp.size() ; i++){
                sum +=abs(idx - temp[i]);
            }
            idx++;
            ans.push_back(sum);
        }
        return ans;
    }
};