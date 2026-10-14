class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i=0,n=nums.size();

        for(i=0;i<n;i++ )
            if(nums[i]==0) break;//find 1st zero 

        for (int j = i + 1; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

    }
};