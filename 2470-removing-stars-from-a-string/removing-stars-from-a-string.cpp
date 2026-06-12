class Solution {
public:
    string removeStars(string s) {
        deque<char>dq;
        for(auto it : s){
            if(it == '*'){
                dq.pop_back();
            }
            else{
                dq.push_back(it);
            }
        }
        string ans = "";
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
        }
        return ans;
    }
};