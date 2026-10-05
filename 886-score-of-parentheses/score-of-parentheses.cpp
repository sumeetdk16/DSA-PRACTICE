class Solution {
public:
    int scoreOfParentheses(string s) {

        int score = 0, depth = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                depth++;          // opening bracket case
            else if (s[i] == ')') // closig  bracket case
            {
                depth--;
                if (s[i - 1] == '(') // add score (2^depth)
                {
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
};