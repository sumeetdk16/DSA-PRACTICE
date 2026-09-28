class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;

        for (auto it : s) {
            if (it == '(') {
                cnt++;
            } else if (it == ')')
                cnt--;
            ans = max(cnt, ans);
        }

        return ans;

        // tc=O(N), sc=O(1)
    }
};