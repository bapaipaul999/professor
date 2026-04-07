class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string ch = s + s;
        return ch.find(goal) != string::npos;
    }
};