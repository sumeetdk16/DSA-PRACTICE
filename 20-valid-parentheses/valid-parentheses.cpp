class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto it : s) {
            if (it == '(')
                st.push(')');
            else if (it == '[')
                st.push(']');
            else if (it == '{')
                st.push('}');
            else if (st.empty() || st.top() != it) {
                return 0; 
            } else
                st.pop(); // st.top==it
        }
        return st.empty();
    }
};