class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int , string>mp;
        for(int i = 0 ; i<names.size() ; i++){
            mp[heights[i]] = names[i];
        }
        int index = names.size()-1;
        vector<string>ans(names.size());
        for(auto it : mp){
            ans[index] = it.second;
            index--;
        }
        return ans;
    }
};