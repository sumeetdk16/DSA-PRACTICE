class Solution {
public:
    int scoreOfParentheses(string s) {

        int score = 0;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') // new start
            {
                res.push_back(score);
                score = 0;
            } else // s[i]==')'
            {
                if (s[i - 1] == '(')
                    score = res.back() + 1;
                else {
                    // nested case s[i]==')'
                    score = res.back() + score * 2;
                }
                res.pop_back();
            }
        }
        return score;
    }
};