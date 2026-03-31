class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int left = 0;
        int right = 0;
        int sum = 0;
        int sum_m = 0;
        int max_sum = 0;

        while(right < customers.size()) {
            sum_m++;
            sum += customers[right] * grumpy[right];

            if(sum_m > minutes) {
                sum_m--;
                sum = sum - customers[left] * grumpy[left];
                left++;
            }

            max_sum = max(max_sum, sum);
            right++;
        }

        for(int i = 0; i < customers.size(); i++) {
            if(grumpy[i] == 0) {
                max_sum += customers[i];
            }
        }

        return max_sum;
    }
};