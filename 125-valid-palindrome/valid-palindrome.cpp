class Solution {
public:
    bool valid(char s){
        if((s>='a' && s<='z')||(s>='A' && s<='Z')||(s>='0' && s<='9')){
            return 1;
        }
        else{
            return 0;
        }
    }
    char lowercase(char s){
        if((s>='a' && s<='z')||(s>='0' && s<='9')){
            return s;
        }
        else{
            char ch = s -'A'+'a';
            return ch;
        }
    }
    int palindrome(string temp){
        int start = 0;
        int end = temp.length()-1;
        while(start < end){
            if(temp[start++] != temp[end--]){
                return 0;
            }
        }
        return 1;
    }
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0 ; i<s.length();i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }
        for( int i = 0 ; i<temp.length();i++){
            temp[i] = lowercase(temp[i]);
        }
        int valid = palindrome(temp);
        if (valid == 0){
            return false;
        }
        else{
            return true;
        }

    }
};