class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        string result = "";

        while (ss >> token) {
            result = token + " " + result;
        }

        result.pop_back(); 
        return result;
    }
};