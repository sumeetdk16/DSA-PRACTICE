class Solution {
public:
    void subsetRecur(int i, vector<int>& arr, vector<vector<int>>& res,
                     vector<int>& subset) {

        // add subset at end of array
        if (i == arr.size()) {
            res.push_back(subset);
            return;
        }

        // include the current value and
        // recursively find all subsets
        subset.push_back(arr[i]);
        subsetRecur(i + 1, arr, res, subset);

        // exclude the current value and
        // recursively find all subsets.
        subset.pop_back();
        subsetRecur(i + 1, arr, res, subset);
    }

    vector<vector<int>> subsets(vector<int>& arr) {

        vector<int> subset;
        vector<vector<int>> res;

        // finding recursively
        subsetRecur(0, arr, res, subset);
        return res;
    }

    int subsetXORSum(vector<int>& nums) {

        int sum = 0, n = nums.size();

        vector<vector<int>> tmp = subsets(nums);

        for (int i = 0; i < tmp.size(); i++) {
            
            vector<int> arr = tmp[i];
            int cnt = 0;
            for (int i = 0; i < arr.size(); i++) {
                cnt ^= arr[i];
            }
            sum += cnt;
        }

        return sum;
    }
};