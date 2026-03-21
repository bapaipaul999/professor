class Solution {
public:
    int maxDistinct(string s) {
        set<char>check;
        int count = 0;
        for(auto ch : s){
            if(check.find(ch)!=check.end()){
                continue;
            }
            check.insert(ch);
            count++;
        }
        return count;
    }
};