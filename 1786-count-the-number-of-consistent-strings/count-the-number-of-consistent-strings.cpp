class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>check;
        for(auto ch : allowed){
            check.insert(ch);
        }
        int count = 0;
        for(auto ch : words){
            int x = 1;
            for(auto t : ch){
                if(check.find(t)==check.end()){
                    x = 0;
                    break;
                }
            }
            count = count +x;
        }
        return count;
    }
};