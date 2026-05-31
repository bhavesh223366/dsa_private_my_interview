class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> last(26);

        // store last occurrence
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string st = "";

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // already present
            if(visited[ch - 'a']) {
                continue;
            }

            // remove larger characters if they appear later
            while(!st.empty() &&
                  st.back() > ch &&
                  last[st.back() - 'a'] > i) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};