class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;

        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
        }

        int target = total - x;

        int i = 0;
        int j = 0;
        int currentSum = 0;
        int maxi = -1;

        while(j < nums.size()){
            currentSum += nums[j];

            while(i <= j && currentSum > target){
                currentSum -= nums[i];
                i++;
            }

            if(currentSum == target){
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }

        if(maxi == -1){
            return -1;
        }

        return nums.size() - maxi;
    }
};