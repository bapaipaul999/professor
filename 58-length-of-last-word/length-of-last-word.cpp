class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int space = 0;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i]==' '){
                if(space == 0){
                    continue;
                }
                else{
                    return count;
                }
            }
            else{
                count++;
                space = 1;
            }

        }
        return count;
    }
};