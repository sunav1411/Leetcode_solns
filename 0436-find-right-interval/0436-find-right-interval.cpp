class Solution{
public:
    vector<int> findRightInterval(vector<vector<int>>& nums){
        vector<int> starts;
        map<int,int> mp;

        for(int idx=0;idx<nums.size();idx++){
            starts.push_back(nums[idx][0]);
            mp[nums[idx][0]]=idx;
        }

        vector<int> ans;
        sort(starts.begin(),starts.end());

        for(int idx=0;idx<nums.size();idx++){
            int end=nums[idx][1];
            auto it=lower_bound(starts.begin(),starts.end(),end);

            if(it==starts.end()) ans.push_back(-1);
            else ans.push_back(mp[*it]);
        }
        return ans;
    }
};