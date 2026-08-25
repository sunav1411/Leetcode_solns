class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]<target){
                cnt+=j-i;
                i++;
            }
            else if(nums[i]+nums[j]>=target){
                j--;
            }
            
        }
        return cnt;
    }
};