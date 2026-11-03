class Solution {
public:
    int minMoves(vector<int>& nums) {

        int max_el = *max_element(nums.begin(), nums.end());

        int moves = 0;
        for (int i = 0; i < nums.size(); i++)
            moves += abs(nums[i] - max_el);

        return moves;
    }
};