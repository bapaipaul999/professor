class Solution {
public:
    int minLengthAfterRemovals(string s) {
       int count1 = 0;
       int count2 = 0;
       for(auto it : s){
            if(it == 'a'){
                count1 ++ ;
            }
            else{
                count2++;
            }
       } 
       return abs(count1-count2);
    }
};