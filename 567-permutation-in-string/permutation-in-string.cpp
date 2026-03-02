class Solution {
public:
    bool check_equal(int count1[26] , int count2[26]){
        for(int i = 0 ; i < 26 ; i++){
            if(count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        int k = 0;
        while(k<s1.length()){
            int char1 = s1[k] - 'a';
            count1[char1]++;
            k++;
        }
        int count2[26] = {0};
        int i = 0;
        while(i<s1.length() && i <s2.length()){
            int char2 = s2[i] - 'a';
            count2[char2]++;
            i++;
        }
        if(check_equal(count1,count2)){
            return true;
        }
        while(i <s2.length()){
            int char2 = s2[i] - 'a';
            count2[char2]++;
            int oldchar = s2[i-s1.length()] - 'a';
            count2[oldchar]--;
            i++;
            if(check_equal(count1,count2)){
                return true;
            }
        }
        return false;
    }
};