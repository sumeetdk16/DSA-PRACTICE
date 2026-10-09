class Solution {
public:
    int minInsertions(string s) {

        int cnt = 0, ans = 0, i = 0;

        while (i < s.length()) {
            if (s[i] == '(') {
                cnt++;
                i++;
            } else // closing brackets
            {
                if (cnt > 0) {
                    cnt--; // closed by open bracket
                } else {
                    ans++; // add a open bracket
                }

                if (s[i + 1] == ')')
                    i += 2;
                else {
                    i += 1;
                    ans++;
                }
            }
        }
        return ans + (cnt * 2);
        // cnt==no of open brakcets remaning
        // ans=no of close brackets rem
    }
};