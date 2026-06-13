class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string , int > mp;
        set<string>st;
        for(int i = 0 ; i<responses.size() ; i++){
            for(int j = 0 ; j <responses[i].size() ;j++){
                if(st.find(responses[i][j])==st.end()){
                    st.insert(responses[i][j]);
                    mp[responses[i][j]]++;
                }

            }
            st.clear();
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
        for(auto it : mp){
            pq.push({-it.second , it.first});
        }
        return pq.top().second;
        
    }
};