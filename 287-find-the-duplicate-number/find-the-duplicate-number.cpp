class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>s1;
        for(auto it : nums){
            if(s1.find(it)!=s1.end()){
                return it;
            }
            s1.insert(it);
        }
        return -1;
    }
};