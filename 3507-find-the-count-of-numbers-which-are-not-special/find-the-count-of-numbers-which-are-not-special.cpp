class Solution {
public:
    bool prime(long long n){
        if(n < 2) return false;

        for(long long i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }

        return true;
    }

    int nonSpecialCount(int l, int r) {

        int special = 0;

        for(long long p = 2; p * p <= r; p++){

            if(prime(p)){
                long long sq = p * p;

                if(sq >= l && sq <= r){
                    special++;
                }
            }
        }

        return (r - l + 1) - special;
    }
};