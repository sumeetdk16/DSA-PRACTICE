class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();
        int min_el = INT_MAX;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            min_el = min(min_el, nums[i]);
        }
        return sum - (n * min_el);
    }
};