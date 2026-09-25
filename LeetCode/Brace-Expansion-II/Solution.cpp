1class Solution {
2public:
3    vector<char> op;
4    vector<vector<string>> st;
5
6    void perf() {
7        int x=st.size()-2, y = st.size()-1;
8        if (op.back()=='+'){
9            // Union
10            st[x].reserve(st[x].size()+st[y].size());
11            st[x].insert(st[x].end(), st[y].begin(), st[y].end());
12        }
13        else { // op.back()=='*'
14            // Concatenation
15            vector<string> nxt;
16            nxt.reserve(st[x].size()*st[y].size());
17            for (const auto& l : st[x]) {
18                for (const auto& r : st[y]) 
19                    nxt.push_back(l+r);
20            }
21            st[x]=move(nxt);
22        }
23        op.pop_back();
24        st.pop_back();
25    }
26    vector<string> braceExpansionII(string& expr) {
27        const int n=expr.size();
28        op.reserve(n);
29
30        char prv='@', cur;
31
32        for (int i=0; i<n; i++, prv=cur) {
33            cur = expr[i];
34            switch (cur) {
35            case ',': 
36                while (!op.empty() && op.back() != '{') perf();
37                op.push_back('+');
38                break;
39            case '{':
40                if (prv=='}' || isalpha(prv)) op.push_back('*');
41                op.push_back('{');
42                break;
43            case '}':
44                while (!op.empty() && op.back()!='{') perf();
45                op.pop_back(); // Remove matching '{'
46                break;
47            default:
48                if (prv=='}') op.push_back('*');
49                string s;
50                for (; i<n && isalpha(expr[i]); i++) s+=expr[i];
51                st.push_back({s});
52                i--;
53                cur=expr[i];
54            }
55        }
56
57        while (!op.empty()) perf();
58
59        auto ans=st.front();
60        sort(ans.begin(), ans.end());
61        ans.erase(unique(ans.begin(), ans.end()), ans.end());
62        return ans;
63    }
64};
65
66auto init = []() {
67    ios::sync_with_stdio(false);
68    cin.tie(nullptr);
69    cout.tie(nullptr);
70    return 'c';
71}();
72
73// Synced seamlessly with LeetHub Pro
74// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
75// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna