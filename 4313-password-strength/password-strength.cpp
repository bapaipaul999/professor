class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        set<char>st;
        for (auto it : password){
            if(st.find(it)==st.end()){
                if(it >='a' && it <='z'){
                ans+=1;
            }
            else if(it >='A' && it <='Z'){
                ans+=2;
            }
            else if(it >='0' && it <='9'){
                ans+=3;
            }
            else{
                ans+=5;
            }
            st.insert(it);
            }
            
        }
        return ans;
    }
};