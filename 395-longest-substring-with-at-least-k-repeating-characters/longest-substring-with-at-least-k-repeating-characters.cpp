class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        int maxLength = 0;

        // Try every possible number of unique characters
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {

            unordered_map<char, int> mp;

            int left = 0;
            int right = 0;

            int unique = 0;         // current unique chars
            int countAtLeastK = 0;  // chars whose freq >= k

            while (right < n) {

                // Expand window
                if (mp[s[right]] == 0)
                    unique++;

                mp[s[right]]++;

                if (mp[s[right]] == k)
                    countAtLeastK++;

                // Shrink if unique chars exceed target
                while (unique > uniqueTarget) {

                    if (mp[s[left]] == k)
                        countAtLeastK--;

                    mp[s[left]]--;

                    if (mp[s[left]] == 0)
                        unique--;

                    left++;
                }

                // Valid window
                if (unique == uniqueTarget &&
                    unique == countAtLeastK) {

                    maxLength = max(maxLength,
                                    right - left + 1);
                }

                right++;
            }
        }

        return maxLength;
    }
};