class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        map<char,int>check;
        for(int i = 0;i<s.size();i++){
            check[s[i]]++;
        }
        for(int i = 0;i<t.size();i++){
            check[t[i]]--;
        }
        for(auto ch : check){
            if(ch.second!=0){
                return false;
            }
        }
        return true;
        
    }
};