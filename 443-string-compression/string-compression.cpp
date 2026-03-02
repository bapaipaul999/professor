class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>char1;
        int i = 0;
        int count = 0;
        while(i<chars.size()){
            if(char1.empty()){
                count++;
                char1.push_back(chars[i]);
                
            }
            else if(chars[i]==chars[i-1]){
                count++;
            }
            else if(chars[i]!=chars[i-1]){
                if(count > 1){
                    string s = to_string(count);
                    for(char c : s){
                        char1.push_back(c);
                    }
                }
                char1.push_back(chars[i]);
                count = 1;

            }
            i++;

        }
        if(count > 1){
            string s = to_string(count);
            for(char c : s){
                char1.push_back(c);
            }
        }
        int count1 = char1.size();
        chars = char1;
        return count1;
    }
};