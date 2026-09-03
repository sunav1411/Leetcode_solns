class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int ginti=0,maxginti=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1)
            ginti++;
        else
            ginti=0;
        maxginti=max(maxginti,ginti);
    }
    return maxginti;     
    }
};