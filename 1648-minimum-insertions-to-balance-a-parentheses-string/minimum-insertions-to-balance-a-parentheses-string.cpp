class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int j = 0;
        int opp = 0;
        while(j<s.size()){
            if(s[j] == ')'){
                if(open == 0){
                    opp++;
                }
                else{
                    open--;
                }
                if(j+1<s.size() && s[j+1]==')'){
                    j++;
                }
                else{
                    opp++;
                }
            }
            else{
                open++;
            }
            j++;
        }
        opp += open*2;
        return opp;
    }
};