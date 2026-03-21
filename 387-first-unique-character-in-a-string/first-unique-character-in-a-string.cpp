class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>check;
        for(auto ch : s){
            check[ch]++;
        }
        for(int i = 0; i< s.size() ; i++){
            if(check[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};