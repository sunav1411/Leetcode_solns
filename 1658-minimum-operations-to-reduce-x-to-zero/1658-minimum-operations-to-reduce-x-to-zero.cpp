class Solution {
public:
    int minOperations(vector<int>& nums, int x) {      
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum-x;

        if(target<0)return -1;

        int l=0;
        int cur=0;
        int len=-1;

        for(int r=0;r<nums.size();r++){
            cur=cur+nums[r];

            while(cur>target){
                cur=cur-nums[l];
                l++;
            }
            if(cur==target){
                len=max(len,r-l+1);

            }
        }
        if(len==-1) return -1;

        return nums.size()-len;


        
    }
};