class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>check;
        vector<int>ans;
        int count = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(check.find(nums[i])==check.end()){
                count++;
            }
            check[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;

        for(auto it : check){
            pq.push({it.second , it.first});
        }

    

        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second) ;
            pq.pop();
        }
        return ans;
    }
};