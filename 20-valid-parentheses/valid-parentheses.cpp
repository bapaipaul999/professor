class Solution {
public:
    bool isValid(string s) {
        stack<char> check;   
        
        for(auto ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                check.push(ch);  
                continue;
            }

            if(check.empty()) return false;   

            if(ch == ')'){
                if(check.top() == '('){
                    check.pop();   
                }
                else{
                    return false;
                }
            }
            else if(ch == ']'){
                if(check.top() == '['){
                    check.pop();
                }
                else{
                    return false;
                }
            }
            else if(ch == '}'){
                if(check.top() == '{'){
                    check.pop();
                }
                else{
                    return false;
                }
            }
        }

        return check.empty();   
    }
};