#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ch1;
        unordered_map<char, char> ch2;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (ch1.find(c1) != ch1.end()) {
                if (ch1[c1] != c2)
                    return false;
            } else {
                ch1[c1] = c2;
            }

            if (ch2.find(c2) != ch2.end()) {
                if (ch2[c2] != c1)
                    return false;
            } else {
                ch2[c2] = c1;
            }
        }

        return true;
    }
};