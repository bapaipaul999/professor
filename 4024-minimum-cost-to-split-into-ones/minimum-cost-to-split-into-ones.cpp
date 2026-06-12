class Solution {
public:
    void find(int n , int &count){
        if(n == 1){
            return;
        }
        int a = 1;
        int b = n-1;
        count = count + a*b;
        find(b , count);
    }
    int minCost(int n) {
        int count = 0;
        find(n , count);
        return count;

    }
};