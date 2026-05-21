class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>mp;
        vector<int>ans;
       
        for(int i = 0; i<A.size() ; i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int index = 0;
            for(auto j : mp){
                if(j.second == 2){
                    index++;
                }
            }
            ans.push_back(index);
        }
        return ans;
    }
};