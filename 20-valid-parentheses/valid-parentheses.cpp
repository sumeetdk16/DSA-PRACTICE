class Solution {
public:
    bool isValid(string s) {

        stack<int> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]); // push opening brackets
            else               // closing bracket
            {
                if (st.empty())
                    return 0;//edge case
                else {
                    if (s[i] == ')') {
                        
                        if (st.top() == '(')
                            st.pop();
                        else
                            return 0;
                    } else if (s[i] == '}') {
                        if (st.top() == '{')
                            st.pop();
                        else
                            return 0;
                    } else // s[i]==']'
                    {
                        if (st.top() == '[')
                            st.pop();
                        else
                            return 0;
                    }
                }
            }
        }

        return st.empty(); // if any brackets are left in stack
    }
};