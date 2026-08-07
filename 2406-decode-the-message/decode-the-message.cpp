class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char , char>mp;
        char ch ='a';
        for(auto i : key){
            if(i == ' '|| mp.find(i)!=mp.end()){
                continue;
            }
            mp[i] = ch;
            ch++;

        }
        for(int i = 0 ; i<message.size() ; i++){
            if(message[i] == ' '){
                continue;
            }
            message[i] = mp[message[i]];
        }
        return message;
    }
};