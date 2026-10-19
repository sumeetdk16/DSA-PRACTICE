class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int tg) {

        vector<int> ans;
        sort(nums.begin(), nums.end());

        int cnt1 = 0; // stores no of el < tg
        int cnt2 = 0; // no of el == tg

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < tg)
                cnt1++;
            else if (nums[i] == tg)
                cnt2++;
        }

        for (int i = cnt1; i < cnt1 + cnt2; i++)
            ans.push_back(i);
        return ans;
    }
};