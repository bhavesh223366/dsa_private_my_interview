class Solution {
public:
    int countPalindrome(string s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            // Odd length palindromes
            count += countPalindrome(s, i, i);

            // Even length palindromes
            count += countPalindrome(s, i, i + 1);
        }

        return count;
    }
};