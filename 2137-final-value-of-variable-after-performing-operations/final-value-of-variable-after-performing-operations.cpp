class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(auto ch  : operations){
            if(ch=="--X"||ch=="X--"){
                count--;
            }
            else if(ch=="++X"||ch=="X++"){
                count++;
            }
        }
        return count;
    }
};