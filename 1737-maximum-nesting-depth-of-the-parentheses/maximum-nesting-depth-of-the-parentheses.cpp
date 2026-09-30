class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;

        for (int it=0;it<s.size();it++) {
            if (s[it] == '(') {
                cnt++;
            } else if (s[it] == ')')
                cnt--;

            ans = max(cnt, ans);
        }

        return ans;

        // tc=O(N), sc=O(1)
    }
};