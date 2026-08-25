class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>hash(n+1);
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                if(nums[i]/k >n) continue;
                hash[nums[i]/k]++;
            }
        }
        int ans=(n+1)*k;
        for(int i=1;i<=n;i++){
            if(hash[i]==0){
                return i*k;
            }
        }
        return ans;
    }
};