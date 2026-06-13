class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;

        for(char c : s){
            mp[c]++;
        }

        string ans = "";

        for(char c : order){
            while(mp[c] > 0){
                ans += c;
                mp[c]--;
            }
        }

        for(char c : s){
            while(mp[c] > 0){
                ans += c;
                mp[c]--;
            }
        }

        return ans;
    }
};