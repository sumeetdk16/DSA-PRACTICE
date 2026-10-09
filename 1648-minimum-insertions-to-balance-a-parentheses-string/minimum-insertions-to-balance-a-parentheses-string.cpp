class Solution {
public:
    int minInsertions(string s) {

        int cnt = 0, ans = 0, n = s.length(), i = 0;
        while (i < n) {

            if (s[i] == '(') {
                cnt++;
                i++;
            }

            else // closing brackets
            {
                if (cnt > 0) {
                    cnt--; // closed by open
                } else {
                    ans++; // add a closing bracket
                }

                if (s[i + 1] == ')')
                    i += 2;
                else

                {
                    i += 1;
                    ans++;
                }
            }
        }
        return ans + cnt * 2;
    }
};