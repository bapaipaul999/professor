class Solution {
public:
    set<string>s1;
    vector<string>ans;
    void f(int idx ,int size , string s){
        if(idx == size){
            if(s1.find(s)==s1.end()){
                ans.push_back(s);
            }
            return;
        }
        f(idx+1 , size , s+'0');
        f(idx+1 , size , s+'1');
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums[0].size();
        for(int i = 0 ; i<nums.size() ; i++){
            s1.insert(nums[i]);
        }
        string s = "";
        f(0 , size , s);
        return ans.size() == 0 ? "" : ans[0];
    }
};