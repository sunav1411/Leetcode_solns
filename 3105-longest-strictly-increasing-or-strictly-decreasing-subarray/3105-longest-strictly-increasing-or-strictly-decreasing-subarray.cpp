class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int c_increasing=1,c_decreasing=1,n=nums.size(),re=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                c_increasing++;
                c_decreasing=1;
            }
            else if(nums[i-1]>nums[i])
            {
                c_decreasing++;
                c_increasing=1;
            }
            else
            {
                c_decreasing=1;
                c_increasing=1;
            }
            re=max(max(c_decreasing,c_increasing),re);
        }
        return re;
    }
};