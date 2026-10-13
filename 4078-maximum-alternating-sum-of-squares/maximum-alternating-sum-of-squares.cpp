class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        // finding squares of el in arr
        for (int i = 0; i < n; i++)
            nums[i] = nums[i] * nums[i];

        // sorting arr
        sort(nums.begin(), nums.end());

        // divide the arr into two half n/2 to maximize the sum
        long long sum1 = accumulate(nums.begin(), nums.begin() + n / 2, 0LL);
        long long sum2 = accumulate(nums.begin() + n / 2, nums.end(), 0LL);

        return sum2 - sum1;
    }
};