class Solution {
public:
    string sortVowels(string s) {
        vector<char>temp;
        set<int>s1;
        for(int i= 0 ; i<s.size() ; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U'){
                s1.insert(i);
                temp.push_back(s[i]);
            }
        }
        int j = 0;
        sort(temp.begin() , temp.end());
        for(int i = 0 ; i<s.size() ; i++){
            if(s1.find(i)!=s1.end()){
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};