class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while(n>1){
            int x = n/2;
            sum = sum + x;
            n = n - x;
        }
        return sum;
    }
};