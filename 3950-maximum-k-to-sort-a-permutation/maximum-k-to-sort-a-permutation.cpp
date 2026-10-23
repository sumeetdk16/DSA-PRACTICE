class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        int k = -1; // all set bits

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i)
                k = k & nums[i];
        }
        return k == -1 ? 0 : k;
    }
};