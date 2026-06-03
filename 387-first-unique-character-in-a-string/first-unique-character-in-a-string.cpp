class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int n = s.length();

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            arr[ch - 'a']++;
        }

        // Find first character with frequency 1
        for (int i = 0; i < n; i++) {
            if (arr[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};