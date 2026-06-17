class Solution {
public:
    string minWindow(string s, string t) {

     // using sliding window + two pointer... o(n) + o()
     // using the interations n
        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int right = 0;

        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            if (freq[s[right]] > 0) {
                count++;
            }

            freq[s[right]]--;

            while (count == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    count--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX
                   ? ""
                   : s.substr(start, minLen);
    }
};