class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, ans = 0;

        for(char c : s) {
            if(c == '(')
                open++;
            else
                close++;

            if(close == open)
                ans = max(ans, 2 * close);

            if(close > open)
                close = open = 0;
        }

        open = close = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')')
                close++;
            else
                open++;

            if(close == open)
                ans = max(ans, 2 * open);

            if(open > close)
                close = open = 0;
        }

        return ans;
    }
};