class Solution {
public:
    string largestOddNumber(string num) {
        int pos = -1;
        string z = "";

        for(int i = 0; i < num.size(); i++){
            int x = num[i] - '0';
            if(x % 2 == 1){
                pos = i;   // store last odd position
            }
        }

        if(pos == -1){
            return z;
        }

        string sum = "";
        for(int i = 0; i <= pos; i++){
            sum += num[i];
        }

        return sum;
    }
};