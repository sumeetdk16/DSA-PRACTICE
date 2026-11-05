class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int min_el=*min_element(nums.begin(),nums.end());
        int moves=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            moves+=nums[i]-min_el;
        }

        return moves;
    }
};