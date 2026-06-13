class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i = 0; i<words.size() ; i++){
            int sum = 0;
            for(auto it : words[i]){
                sum = sum + weights[it - 'a'];

            }
            int x = sum%26;
            ans = ans + char((26-1-x) + 'a');
        }
        return ans;
    }
};