class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++) {
            int hash[101]={0};
            int diff=0;
            for(int j=i; j<n; j++) {
                hash[nums[j]]++;
                if(hash[nums[j]]>1) {
                    diff++;
                }
                ans+=((j-i+1)-diff)*((j-i+1)-diff);
            }
        }
        return ans;
    }
};