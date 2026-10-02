class Solution {
public:
    // bool isvalid(string s) {
    //     int cnt = 0;
    //     for (int i = 0; i < s.size(); i++) {

    //         if (s[i] == '(')
    //             cnt++;
    //         else if (s[i] == ')' && cnt == 0) // invalid  Parentheses
    //             return 0;
    //         else
    //             cnt--;
    //     }
    //     return cnt == 0;
    // }

    void solve(string& s, int n, vector<string>& ans, int open, int close) {

        if (s.size() == n * 2) {
            // if (isvalid(s) == 1)
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');                  // do
            solve(s, n, ans, open + 1, close); // explore
            s.pop_back();                      // undo
        }

        if (open>close) {
            s.push_back(')');                  // do
            solve(s, n, ans, open, close + 1); // explore
            s.pop_back();                      // undo
        }
    }
    vector<string> generateParenthesis(int n) {

        int open = 0, close = 0;
        vector<string> ans; // global variable
        string s = "";
        solve(s, n, ans, open, close);
        return ans;
    }
};