class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(auto it : s){
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' ||it == 'u'){
                count ++;
            }
        }
        if(count%2 == 1){
            return true;
        }
        if(count==0){
            return false;
        }
        return true;
    }
};