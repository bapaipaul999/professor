class Solution {
public:
    void f(int idx , vector<string>input ,string s ,  vector<string>& ans){
        if(idx == input.size()){
            ans.push_back(s);
            return ;
        }
        for(auto ch : input[idx]){
            f(idx+1 , input , s+ch , ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int  , string>mp;
        char el = 'a';
        int i = 2;
        while(el <= 'z'){
           string s = "";
           int x = 0;
           while(x < 3 && el<='z'){
            s+=el;
            x++;
            el++;
           } 
           if((i == 7 || i == 9)&& el<='z'){
            s+=el;
            el++;
           }
           mp[i]= s;
           i++;
        }
        vector<string>input;
        int j = 0;
        while(j<digits.size()){
            int x = digits[j] - '0';
            input.push_back(mp[x]);
            j++;
        }
        vector<string>ans;
        f(0 , input ,"" , ans);
        return ans;

    }
};