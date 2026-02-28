class Solution {
public:
    int peekvalue(vector<int>&arr){
        int start = 0;
        int size = arr.size(); 
        int end = size - 1; 
        int mid = start + (end-start)/2;
        int mountain = 0;
        while(start < end ){
            int mid = start + (end-start)/2;
            mountain = mid;

            
            if(arr[mid] > arr[mid+1]){ 
                end = mid;
            } 
            else{ 
                start = mid+1;
            } 
        } 
        return start; 
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int x = peekvalue(arr);
        return x;
    }
};