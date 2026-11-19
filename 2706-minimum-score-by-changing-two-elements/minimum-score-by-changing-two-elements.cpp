class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());


        int low = 0, high;//low is always zero in any case we equal two numbers 

        high = min({(nums[n - 2] - nums[1]), (nums[n - 3] - nums[0]),
                    (nums[n - 1] - nums[2])});
        return low + high;
    }
};