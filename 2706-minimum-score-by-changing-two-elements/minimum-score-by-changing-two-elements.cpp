class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        // low=0
        //  low is always zero in all 3 case's we equal two numbers

        int high = min({(nums[n - 2] - nums[1]), (nums[n - 3] - nums[0]),
                        (nums[n - 1] - nums[2])});

        return high; // low+high
    }
};