class Solution {
public:
    bool isvalid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')' && cnt == 0) // invalid  Parentheses
                return 0;
            else
                cnt--;
        }
        return cnt == 0;
    }
    void solve(string& s, int n, vector<string>& ans) {
        if (s.size() == n * 2) {
            if (isvalid(s) == 1)
                ans.push_back(s);
            return;
        }

        s.push_back('('); // do
        solve(s, n, ans); // explore
        s.pop_back();     // undo

        s.push_back(')'); // do
        solve(s, n, ans); // explore
        s.pop_back();     // undo
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans; // global var

        string s = "";
        solve(s, n, ans);
        return ans;
    }
};