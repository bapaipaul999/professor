class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
      int depth = 0;
      vector<int>ans;
      for(int i = 0 ; i<seq.size() ; i++){
            if(seq[i] == '('){
                depth++;
                if(depth%2 == 0){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                if(depth%2 == 0){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
                depth--;
            }
      } 
      return ans; 
    }
};