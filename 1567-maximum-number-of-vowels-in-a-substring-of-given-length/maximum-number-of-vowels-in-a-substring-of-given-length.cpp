class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int total = 0;
        int vowels = 0;

        while (right < s.size()) {
            if (count < k) {
                if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
                    vowels++;
                }
                right++;
                count++;

                if (count == k) {
                    total = max(total, vowels);
                }
                continue;
            }

            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') {
                vowels--;
            }

            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
                vowels++;
            }

            total = max(total, vowels);
            left++;
            right++;
        }

        return total;
    }
};