class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int ans=0 ;
        sort(nums.begin(), nums.end()) ;
        for(int num:nums){
            mp[num]++ ;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]==1){
                ans = max(ans,mp[nums[i-1]]+mp[nums[i]]) ;
            }
            else{
                continue ;
            }
        }

        return ans ;

    }
};