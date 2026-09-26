class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string , string>mp;
        for(int i = 0 ; i<knowledge.size() ; i++){
            mp[knowledge[i][0]] = knowledge[i][1];

        }
        string ans = "";
        int i = 0;
        while(i<s.size()){
            if(s[i] == '('){
                string x = "";
                i++;
                while(i<s.size() && s[i]!=')'){
                    x+=s[i];
                    i++;
                }
                if(mp.find(x)!=mp.end()){
                    ans+=mp[x];
                }
                else{
                    ans+='?';
                }

            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};