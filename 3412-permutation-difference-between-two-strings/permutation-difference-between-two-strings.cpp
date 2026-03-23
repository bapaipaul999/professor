class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char,int>check1;
        
        for(int i = 0; i<s.size(); i++){
            check1[s[i]]+=i;
            check1[t[i]]-=i;

        }
        int count = 0;
        for(auto i : check1){
            if(i.second<0){
                i.second = -i.second;
            }
            count+=i.second;
        }
        return count;

    }
};