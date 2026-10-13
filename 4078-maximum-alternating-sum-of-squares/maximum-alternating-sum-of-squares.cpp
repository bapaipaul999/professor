class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<long long>q1;
        for(int i = 0 ; i<nums.size() ; i++){
            q1.push(pow(nums[i] , 2));
        }
        int n = nums.size();
        int plus ;
        if(n%2 == 0){
            plus = n/2;
        }
        else{
            plus  = (n+1)/2;
        }
        long long ans = 0;
        while(!q1.empty()){
            if(plus>0){
                ans+=q1.top();
                plus--;
            }
            else{
                ans-=q1.top();
            }
            q1.pop();
        }
        return ans;

    }
};