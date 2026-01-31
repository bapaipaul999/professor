class Solution {
public:
    int reverse(int x) {
        double reverse = 0;
        if (x < -pow(2, 31) || x > pow(2, 31) - 1){
            return reverse;
        }
        while(x!=0){
            int residue = x%10;
            reverse = reverse*10 + residue;
            x = x/10;
        }
        if (reverse < -pow(2, 31) || reverse > pow(2, 31) - 1){
            return 0;
        }
        return reverse;
    }
};