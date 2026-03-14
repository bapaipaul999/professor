class Solution {
public:
    int max_element(vector<vector<int>>& nums , int mid , int n ){
        int maxi = -1;
        int x = -1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i][mid] > maxi){
                maxi = nums[i][mid];
                x = i;
            }
        }

        return x;
    }

    vector<int> findPeakGrid(vector<vector<int>>& nums) {

        int n = nums.size();
        int m = nums[0].size();

        int start = 0;
        int end = m - 1;

        while(start <= end){

            int mid = start + (end - start)/2;

            int x = max_element(nums, mid, n);

            int left  = mid > 0 ? nums[x][mid-1] : -1;
            int right = mid + 1 < m ? nums[x][mid+1] : -1;

            if(nums[x][mid] > left && nums[x][mid] > right){
                return {x, mid};
            }
            else if(nums[x][mid] < left){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return {-1,-1};
    }
};