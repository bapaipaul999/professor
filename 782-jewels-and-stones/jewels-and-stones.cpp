class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char>check;
        for(auto ch : jewels){
            check.insert(ch);
        }
        int count = 0;
        for(auto ch : stones){
            if(check.find(ch)!=check.end()){
                count++;
            }
        }
        return count;

    }
};