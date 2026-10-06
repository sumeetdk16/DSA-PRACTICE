class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push('(');
            else {
                if (st.empty())
                    cnt++;
                else
                    st.pop();
            }
        }

        int ans = st.size() + cnt;
        return ans;
    }
};