class Solution {
public:
    vector<string> ans; // global var

    bool isvalid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')' && cnt == 0)//invalid  Parentheses
                return 0;
            else
                cnt--;
        }
        return cnt == 0;
    }
    void solve(string& s, int n) {
        if (s.size() == n * 2) {
            if (isvalid(s) == 1)
                ans.push_back(s);
            return;
        }

        s.push_back('('); // do
        solve(s, n);      // explore
        s.pop_back();     // undo

        s.push_back(')'); // do
        solve(s, n);      // explore
        s.pop_back();     // undo
    }
    vector<string> generateParenthesis(int n) {

        string s = "";

        solve(s, n);

        return ans;
    }
};