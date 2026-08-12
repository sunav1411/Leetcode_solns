class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int i=0;
        int j=0;

        int sabse=0;

        while(j<nums.size()) {
            mp[nums[j]]+=1;
            while(mp[nums[j]]>k) {
                mp[nums[i]]-=1;
                i++;
            }
            sabse=max(sabse,j-i+1);
            j++;
        }
        return sabse;
    }
};