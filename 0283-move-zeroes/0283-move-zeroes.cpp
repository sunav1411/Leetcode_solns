class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]!=0){
            int temp=nums[left];
            nums[left]=nums[r];
            nums[r]=temp;
            left++;


            }
        }
    }
};