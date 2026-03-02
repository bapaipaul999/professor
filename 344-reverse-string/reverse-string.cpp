class Solution {
public:
    void reverseString(vector<char>& s) {
        int count = s.size();
        // for(int i = 0 ; s[i]!= '\0' ; i++){
        //     count++;
        // }
        int start = 0;
        int end = count - 1;
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
};