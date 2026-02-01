class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        }
        for(int i = 0 ; pow(2,i)<=n;i++){
            if(pow(2,i)==n){
                return true;
            }
        }
        return false;
    }
};