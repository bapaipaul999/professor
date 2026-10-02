class Solution {
public:
    void f(int x , int n , string s , vector<string>&ans){
        if(n == 0){
            ans.push_back(s);
            return;
        }
        f(1 , n-1 , s +'1' , ans);
        if(x!=0){
            f(0 , n-1 , s +'0' , ans);
        }
    }
    vector<string> validStrings(int n) {
        string s= "";
        vector<string>ans;
        f(1 , n , s , ans);
        return ans;
    }
};