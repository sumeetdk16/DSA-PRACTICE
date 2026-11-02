class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();

        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int mid_el = nums[n / 2], moves = 0;

        for (int i = 0; i < n; i++) {
            moves += abs(nums[i] - mid_el);
        }

        return moves;
    }
};