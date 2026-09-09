class Solution {
public:
    long long countCommas(long long n) {

        if(n < 1000) return 0;

        long long y = 0;

        for(long long i = 999; i <= n; i = i * 1000 + 999){

            if(n > i){
                y += (n - i);
            }
            else{
                return y;
            }
        }

        return y;
    }
};