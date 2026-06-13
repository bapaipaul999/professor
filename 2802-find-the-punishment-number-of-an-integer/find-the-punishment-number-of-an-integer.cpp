class Solution {
public:
    bool check(int num, int target) {
        if (num == target)
            return true;

        if (num < target)
            return false;

        int p = 10;

        while (p <= num * 10) {
            int part = num % p;

            if (part <= target && check(num / p, target - part))
                return true;

            p *= 10;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (check(i * i, i)) {
                sum += i * i;
            }
        }

        return sum;
    }
};