class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        
        // Base case: If the string is shorter than k, it's impossible to have a valid substring
        if (n < k) return 0;
        
        // Step 1: Count the frequency of each character in the current string
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Step 2: Find the first character that appears less than k times
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] < k) {
                
                // We found an invalid character. Split the string here.
                // Recursively check the left part
                int leftPart = longestSubstring(s.substr(0, i), k);
                
                // Skip any consecutive invalid characters to avoid unnecessary splits
                int j = i + 1;
                while (j < n && freq[s[j] - 'a'] < k) {
                    j++;
                }
                
                // Recursively check the right part
                int rightPart = longestSubstring(s.substr(j), k);
                
                // Return the maximum length found in either half
                return max(leftPart, rightPart);
            }
        }
        
        // Step 3: If we reach here, every character in the string appears at least k times
        return n;
    }
};