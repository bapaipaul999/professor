class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> check1;
        map<string,int> check2;
        for(auto ch : words1){
            check1[ch]++;
        }
        for(auto ch : words2){
            check2[ch]++;
        }
        int count = 0;
        for(auto ch : words2){
            if(check1[ch]==1 && check2[ch] == 1){
                count++;
            }
        }
        return count;
    }
};