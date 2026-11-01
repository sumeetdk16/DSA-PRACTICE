class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();

        int min_el = *min_element(nums.begin(), nums.end());

        int opr = 0;
        for (int i = 0; i < nums.size(); i++) {
            opr += (nums[i] - min_el);
        }

        return opr;
    }
};