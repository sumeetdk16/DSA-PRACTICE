class Solution {
public:
    int longestValidParentheses(string s) {

        if (s.length() == 0)
            return 0; // edge case

        int open_l = 0, close_l = 0, open_r = 0, close_r = 0, maxlen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            // brackets case for left side
            if (s[i] == '(')
                open_l++;
            else
                close_l++;
            // left  Parentheses case
            if (close_l == open_l) // valid Parentheses
                maxlen = max(maxlen, open_l + close_l);
            else if (close_l > open_l) // invalid Parentheses
                open_l = close_l = 0;  // reset counter

            // brackets case for right side
            if (s[n - i - 1] == '(')
                open_r++;
            else
                close_r++;
            // right Parentheses case
            if (close_r == open_r) // valid Parentheses
                maxlen = max(maxlen, open_r + close_r);
            else if (open_r > close_r) // invalid Parentheses
                open_r = close_r = 0;  // reset counter
        }
        return maxlen;
    }
};