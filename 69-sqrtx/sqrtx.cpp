class Solution {
public:
    long long int binarysearch(int x){
        int start = 1;
        int end = x;
        int ans = 0 ;
        while(start <= end ) {
            long long int mid = start + (end - start)/2;
            long long int y = mid*mid;
            if( y == x ){
                return mid;
            }
            if(y > x ){
                end = mid -1;

            }
            else{
                ans = mid;
                start = mid+1;
            }

        }
        return ans;
    }
    int mySqrt(int x) {
        int a = binarysearch(x);
        return a;
        
    }
};