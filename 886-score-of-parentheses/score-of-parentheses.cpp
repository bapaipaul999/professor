class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int>temp;
        int score = 0;

        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '('){
                temp.push_back(score);
                score= 0;
            }
            else{
                if(s[i-1] == '('){
                    score = temp.back() + 1;
                }
                else{
                    score = temp.back()+2*score;
                }
                temp.pop_back();
            }
        }
        return score;
       
    }
};