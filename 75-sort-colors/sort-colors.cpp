class Solution {
public:
    int partition(vector<int>& nums , int low , int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i<j){
            while(nums[i] <= pivot && i <= high-1){
                i++;
            }
            while(nums[j] > pivot && j >= low+1){
                j--;
            }
            if(i<j){
                swap(nums[i] , nums[j]);
            }

        }
        swap(nums[j],nums[low]);
        return j;
    }
    void quicksort(vector<int>& nums , int low , int high){
        if(low<high){
            int pIndex = partition(nums,low,high);
            quicksort(nums,low,pIndex-1);
            quicksort(nums,pIndex+1,high);
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size() - 1;
        quicksort(nums,0,n);
    }
};