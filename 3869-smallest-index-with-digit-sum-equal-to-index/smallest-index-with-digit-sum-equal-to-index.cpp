class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int sum=0;
            int indx=i;

            while(num!=0)
            {
                sum+=num%10;
                num=num/10;
            }
            if(sum==indx) return indx;
        }
        return -1;
        
    }
};