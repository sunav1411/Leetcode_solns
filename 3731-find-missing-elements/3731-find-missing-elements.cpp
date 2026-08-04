class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans= {};
        int n=nums.size();
        unordered_map<int, int> m;
        for (int x:nums) {
            m[x]++;
        }

        int mn=*min_element(nums.begin(), nums.end());
        int mx=*max_element(nums.begin(), nums.end());
        for(int i = mn; i <= mx; i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};