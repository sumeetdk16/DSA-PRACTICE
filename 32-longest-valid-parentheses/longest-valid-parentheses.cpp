class Solution {
public:
    int longestValidParentheses(string s) {

        if (s.length() == 0)
            return 0; // edge case

        int open = 0, close = 0, maxlen = 0;

        // left to right traversal
        for (int i = 0; i < s.length(); i++) {
            // brackets case
            if (s[i] == '(')
                open++;
            else
                close++;

            if (close == open) // valid Parentheses
                maxlen = max(maxlen, open + close);

            else if (close > open) // invalid Parentheses
                open = close = 0;  // reset counter
        }

        open = close = 0;

        // right to left traversal
        for (int i = s.length() - 1; i > 0; i--) {
            // brackets case
            if (s[i] == '(')
                open++;
            else
                close++;

            if (close == open) // valid Parentheses
                maxlen = max(maxlen, open + close);

            else if (open > close) // invalid Parentheses
                open = close = 0;  // reset counter
        }

        return maxlen;

        
    }
};