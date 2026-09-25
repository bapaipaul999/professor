class Solution {
public:
    int minSwaps(string s) {
        int start = 0;
        int end = s.size()-1;
        int close = 0;
        int swaps = 0;
        while(start < end){
            if(s[start] == ']'){
                close++;
            }
            else{
                close--;
                start++;
                continue;
            }
            if(close>0){
                while(s[end]==']'&&start<end){
                    end--;
                }
                if(s[end] =='['){
                    swap(s[start] , s[end]);
                    swaps++;
                    close = close-2;
                    end--;
                }
            }
            start++;

        }
        return swaps;
    }
};