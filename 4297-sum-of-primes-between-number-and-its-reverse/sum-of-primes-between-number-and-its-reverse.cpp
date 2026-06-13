class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int rev = 0;
        int temp = n;

        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        int l = min(n, rev);
        int r = max(n, rev);

        int sum = 0;

        for (int i = l; i <= r; i++) {
            if (i < 2) continue;

            bool prime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) {
                sum += i;
            }
        }

        return sum;
    }
};