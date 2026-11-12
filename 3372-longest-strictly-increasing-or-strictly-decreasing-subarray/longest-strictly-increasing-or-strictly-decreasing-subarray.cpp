class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // Step 1: Initialize increasing and decreasing lengths.
        int inc = 1, dec = 1, answer = 1;

        // Step 2: Process each adjacent pair.
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = dec = 1;
            }

            // Step 3: Update the maximum length.
            answer = max({answer, inc, dec});
        }

        // Step 4: Return the result.
        return answer;
    }
};