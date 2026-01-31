class Solution {
public:
    int subtractProductAndSum(int n) {
       int product = 1;
       int sum = 0;
       while(n>0){
        int residue = n%10;
        product = product*residue;
        sum = sum + residue;
        n = n/10;
       } 
       return product - sum;
    }
};