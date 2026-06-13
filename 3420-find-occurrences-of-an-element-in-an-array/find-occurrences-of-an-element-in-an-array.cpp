class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>temp;
        for(int i = 0 ; i <nums.size() ; i++){
            if(nums[i] == x){
                temp.push_back(i);
            }
        }
        for(int i = 0 ; i<queries.size() ; i++){
            if(temp.size()<queries[i]){
                queries[i] = -1;
            }
            else{
                int x = queries[i];
                queries[i] = temp[x-1];
            }
        }
        return queries;
    }
};