class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int sum = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                set<int> st;
                for (int k = i; k <= j; k++) {
                    st.insert(nums[k]);
                }

                sum+=(st.size()*st.size());
            }
        }

        return sum;
    }
};