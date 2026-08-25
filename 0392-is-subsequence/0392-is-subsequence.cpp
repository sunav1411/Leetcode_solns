class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i =0;
        int j = 0;  

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;          // character of s matched
            }
            j++;              // move in t always
        }

        return i == s.size();
    }
};