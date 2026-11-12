class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();

        stack<int> st1;
        stack<int> st2;

        st1.push(nums[0]);
        st2.push(nums[n - 1]);
        int ans = 1;

        for (int i = 1; i < nums.size(); i++) {

            // inc case
            if (st1.top() < nums[i]) {
                st1.push(nums[i]);
                ans = max(ans, (int)st1.size());
            } else {
                // clear stack
                while (!st1.empty())
                    st1.pop();
                st1.push(nums[i]);
            }

            // dec case
            if (st2.top() < nums[n - i - 1]) {

                st2.push(nums[n - i - 1]);
                ans = max(ans, (int)st2.size());
            } else {
                // clear stack
                while (!st2.empty())
                    st2.pop();
                st2.push(nums[n - i - 1]);
            }
        }
        return ans;
    }
};