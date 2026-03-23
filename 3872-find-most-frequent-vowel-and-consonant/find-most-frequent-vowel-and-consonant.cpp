class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>check1;
        map<char,int>check2;
        for(auto ch : s){
            if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ){
                check1[ch]++;
            }
            else{
                check2[ch]++;
            }
        }
        int x = 0;
        int y = 0;
        for(auto ch : check1){
            x = max(x,ch.second);
        }
        for(auto ch : check2){
            y = max(y,ch.second);
        }
        return x+y;

    }
};