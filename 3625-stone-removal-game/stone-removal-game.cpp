class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool alice = false;
        int m = n;
        while(true){
            if(m>=x){
                m = m - x;
                alice = !alice;
                x--;
            }
            else{
                return alice;
            }
        }
        return alice;
    }
};